// ============================================
// GITHUB OAUTH CONFIGURATION
// ============================================
// TODO: Replace these placeholders with your GitHub OAuth app credentials
const GITHUB_CLIENT_ID = 'Ov23liYLlWgff0wIqfML'; // Get from: https://github.com/settings/developers
const GITHUB_REDIRECT_URI = 'https://loudwave.vercel.app/callback.html'; // ✅ Must match GitHub OAuth App settings exactly
const GITHUB_SCOPES = 'user:email repo workflow'; // Scopes needed for your app

// ============================================
// OAUTH FLOW
// ============================================

/**
 * Initiates GitHub OAuth login
 * Redirects user to GitHub's OAuth authorization page
 */
function initGitHubLogin() {
    const authUrl = `https://github.com/login/oauth/authorize?client_id=${GITHUB_CLIENT_ID}&redirect_uri=${encodeURIComponent(GITHUB_REDIRECT_URI)}&scope=${encodeURIComponent(GITHUB_SCOPES)}`;
    
    // Show loading dialog
    showLoginDialog();
    
    // Redirect to GitHub OAuth
    window.location.href = authUrl;
}

/**
 * Exchange authorization code for access token
 * ✅ Calls Vercel serverless function to securely exchange code
 * The CLIENT_SECRET is stored in Vercel env vars (never exposed to frontend)
 * 
 * Vercel serverless function: /api/github/callback.js
 * POST /api/github/callback
 * Body: { code: string }
 * Response: { access_token: string }
 */
async function exchangeCodeForToken(code) {
    try {
        // ✅ Using relative path - Vercel serverless function handles token exchange securely
        const response = await fetch('/api/github/callback', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ code })
        });

        if (!response.ok) {
            throw new Error('Failed to exchange code for token');
        }

        const data = await response.json();
        return data.access_token;
    } catch (error) {
        console.error('Token exchange error:', error);
        hideLoginDialog();
        alert('Login failed. Please try again.');
        return null;
    }
}

/**
 * Fetch user data from GitHub API
 * TODO: This requires the access token from the GitHub OAuth flow
 */
async function fetchGitHubUserData(accessToken) {
    try {
        const response = await fetch('https://api.github.com/user', {
            headers: {
                'Authorization': `Bearer ${accessToken}`,
                'Accept': 'application/vnd.github.v3+json'
            }
        });

        if (!response.ok) {
            throw new Error('Failed to fetch user data');
        }

        const userData = await response.json();
        return userData;
    } catch (error) {
        console.error('User data fetch error:', error);
        return null;
    }
}

/**
 * Fetch user email from GitHub API
 */
async function fetchGitHubUserEmail(accessToken) {
    try {
        const response = await fetch('https://api.github.com/user/emails', {
            headers: {
                'Authorization': `Bearer ${accessToken}`,
                'Accept': 'application/vnd.github.v3+json'
            }
        });

        if (!response.ok) {
            throw new Error('Failed to fetch user email');
        }

        const emails = await response.json();
        // Get primary email or first email
        const primaryEmail = emails.find(e => e.primary) || emails[0];
        return primaryEmail.email;
    } catch (error) {
        console.error('Email fetch error:', error);
        return null;
    }
}

// ============================================
// LOCAL STORAGE & SESSION MANAGEMENT
// ============================================

/**
 * Save user data to localStorage
 * TODO: Consider using a more secure method (sessionStorage, encrypted storage, etc.)
 */
function saveUserData(userData, accessToken) {
    const userInfo = {
        username: userData.login,
        name: userData.name,
        email: userData.email || '',
        avatar: userData.avatar_url,
        accessToken: accessToken, // Store securely - consider alternatives
        loginTime: new Date().toISOString()
    };
    
    localStorage.setItem('github_user', JSON.stringify(userInfo));
    localStorage.setItem('github_access_token', accessToken);
}

/**
 * Get user data from localStorage
 */
function getUserData() {
    const userData = localStorage.getItem('github_user');
    return userData ? JSON.parse(userData) : null;
}

/**
 * Get access token from localStorage
 * TODO: Implement secure token storage (consider using secure cookies or other methods)
 */
function getAccessToken() {
    return localStorage.getItem('github_access_token');
}

/**
 * Logout user
 */
function logoutUser() {
    localStorage.removeItem('github_user');
    localStorage.removeItem('github_access_token');
    updateUIAfterLogout();
}

// ============================================
// UI MANAGEMENT
// ============================================

/**
 * Show loading dialog with "Logging you in!" message
 */
function showLoginDialog() {
    const dialog = document.getElementById('login-dialog');
    if (dialog) {
        dialog.style.display = 'flex';
    }
}

/**
 * Hide loading dialog
 */
function hideLoginDialog() {
    const dialog = document.getElementById('login-dialog');
    if (dialog) {
        dialog.style.display = 'none';
    }
}

/**
 * Update UI after successful login
 */
function updateUIAfterLogin(userData) {
    // Hide the "Login to GitHub" button
    const loginButtons = document.querySelectorAll('.nav-links a[href*="github.com/login"]');
    loginButtons.forEach(btn => {
        btn.style.display = 'none';
    });

    // Show user profile section in navbar
    const navRight = document.querySelector('.nav-right');
    if (navRight) {
        navRight.innerHTML = `
            <div class="user-profile">
                <img src="${userData.avatar}" alt="${userData.username}" class="user-avatar" title="${userData.username}">
                <span class="user-name">${userData.username}</span>
                <button onclick="logoutUser()" class="logout-btn" title="Logout">
                    <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2">
                        <path d="M9 21H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h4"></path>
                        <polyline points="16 17 21 12 16 7"></polyline>
                        <line x1="21" y1="12" x2="9" y2="12"></line>
                    </svg>
                </button>
            </div>
        `;
    }

    hideLoginDialog();
}

/**
 * Update UI after logout
 */
function updateUIAfterLogout() {
    // Show the "Login to GitHub" button again
    const loginButtons = document.querySelectorAll('.nav-links a[href*="github.com/login"]');
    loginButtons.forEach(btn => {
        btn.style.display = 'inline-block';
    });

    // Hide user profile section
    const navRight = document.querySelector('.nav-right');
    if (navRight) {
        navRight.innerHTML = '';
    }

    // Reload page to reset state
    location.reload();
}

// ============================================
// INITIALIZATION & PAGE LOAD
// ============================================

/**
 * Check if user is already logged in on page load
 */
function checkAuthStatus() {
    const userData = getUserData();
    
    if (userData) {
        updateUIAfterLogin(userData);
    }
}

/**
 * Handle callback from GitHub OAuth redirect
 * This should be called on your callback page (callback.html)
 */
function handleGitHubCallback() {
    const params = new URLSearchParams(window.location.search);
    const code = params.get('code');
    const error = params.get('error');

    if (error) {
        console.error('GitHub OAuth error:', error);
        alert('Login failed: ' + error);
        window.location.href = '/'; // Redirect to home
        return;
    }

    if (code) {
        // Exchange code for token
        exchangeCodeForToken(code).then(async (accessToken) => {
            if (accessToken) {
                // Fetch user data
                const userData = await fetchGitHubUserData(accessToken);
                if (userData) {
                    // Fetch user email
                    const email = await fetchGitHubUserEmail(accessToken);
                    userData.email = email;

                    // Save user data
                    saveUserData(userData, accessToken);

                    // Redirect back to home page
                    hideLoginDialog();
                    window.location.href = '/';
                } else {
                    alert('Failed to fetch user data');
                    window.location.href = '/';
                }
            }
        });
    }
}

// Check auth status when page loads
document.addEventListener('DOMContentLoaded', checkAuthStatus);

// ============================================
// GITHUB API HELPER FUNCTIONS
// ============================================
// TODO: These functions require an authenticated access token

/**
 * Clone a repository
 * TODO: This needs backend support for actual cloning
 */
async function cloneRepository(repoUrl) {
    const accessToken = getAccessToken();
    if (!accessToken) {
        alert('Please login first');
        return;
    }

    try {
        // TODO: Implement Vercel serverless function for cloning
        // Backend should handle: git clone, authentication, file system access
        const response = await fetch('/api/repo/clone', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Authorization': `Bearer ${accessToken}`
            },
            body: JSON.stringify({ repoUrl })
        });

        if (!response.ok) {
            throw new Error('Clone failed');
        }

        alert('Repository cloned successfully!');
    } catch (error) {
        console.error('Clone error:', error);
        alert('Failed to clone repository');
    }
}

/**
 * Start GitHub Actions workflow
 * TODO: This needs a specific workflow ID/name
 */
async function startWorkflow(owner, repo, workflowId) {
    const accessToken = getAccessToken();
    if (!accessToken) {
        alert('Please login first');
        return;
    }

    try {
        const response = await fetch(
            `https://api.github.com/repos/${owner}/${repo}/actions/workflows/${workflowId}/dispatches`,
            {
                method: 'POST',
                headers: {
                    'Authorization': `Bearer ${accessToken}`,
                    'Accept': 'application/vnd.github.v3+json'
                },
                body: JSON.stringify({ ref: 'main' }) // TODO: Adjust ref as needed
            }
        );

        if (!response.ok) {
            throw new Error('Failed to start workflow');
        }

        alert('Workflow started successfully!');
    } catch (error) {
        console.error('Workflow start error:', error);
        alert('Failed to start workflow');
    }
}

/**
 * Stop GitHub Actions workflow run
 * TODO: This needs a specific run ID
 */
async function stopWorkflow(owner, repo, runId) {
    const accessToken = getAccessToken();
    if (!accessToken) {
        alert('Please login first');
        return;
    }

    try {
        const response = await fetch(
            `https://api.github.com/repos/${owner}/${repo}/actions/runs/${runId}/cancel`,
            {
                method: 'POST',
                headers: {
                    'Authorization': `Bearer ${accessToken}`,
                    'Accept': 'application/vnd.github.v3+json'
                }
            }
        );

        if (!response.ok) {
            throw new Error('Failed to stop workflow');
        }

        alert('Workflow stopped successfully!');
    } catch (error) {
        console.error('Workflow stop error:', error);
        alert('Failed to stop workflow');
    }
}
