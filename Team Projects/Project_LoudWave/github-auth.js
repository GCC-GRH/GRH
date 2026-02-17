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

/**
 * Open logout confirmation modal
 */
function openLogoutConfirmation() {
    const modal = document.getElementById('logout-confirmation-modal');
    if (modal) {
        modal.style.display = 'flex';
    }
}

/**
 * Confirm logout and clear data
 */
function confirmLogout() {
    localStorage.removeItem('github_user');
    localStorage.removeItem('github_access_token');
    sessionStorage.clear();
    
    // Close the modal
    const modal = document.getElementById('logout-confirmation-modal');
    if (modal) {
        modal.style.display = 'none';
    }
    
    // Close the dropdown
    closeUserDropdown();
    
    updateUIAfterLogout();
}

/**
 * Cancel logout
 */
function cancelLogout() {
    const modal = document.getElementById('logout-confirmation-modal');
    if (modal) {
        modal.style.display = 'none';
    }
}

/**
 * Toggle user dropdown menu (desktop)
 */
function toggleUserDropdown() {
    const dropdown = document.getElementById('user-dropdown-menu');
    if (dropdown) {
        const isOpen = dropdown.classList.toggle('open');
        
        // Close other dropdowns if any
        if (isOpen) {
            document.addEventListener('click', closeDropdownOnClickOutside);
        } else {
            document.removeEventListener('click', closeDropdownOnClickOutside);
        }
    }
}

/**
 * Toggle mobile navigation menu
 */
function toggleMobileMenu() {
    const mobileMenu = document.getElementById('mobile-nav-menu');
    const menuIcon = document.getElementById('mobile-menu-icon');
    
    if (mobileMenu) {
        mobileMenu.classList.toggle('active');
        menuIcon.classList.toggle('active');
        document.body.style.overflow = mobileMenu.classList.contains('active') ? 'hidden' : 'auto';
    }
}

/**
 * Close mobile menu
 */
function closeMobileMenu() {
    const mobileMenu = document.getElementById('mobile-nav-menu');
    const menuIcon = document.getElementById('mobile-menu-icon');
    
    if (mobileMenu && mobileMenu.classList.contains('active')) {
        mobileMenu.classList.remove('active');
        menuIcon.classList.remove('active');
        document.body.style.overflow = 'auto';
    }
}

/**
 * Close user dropdown menu
 */
function closeUserDropdown() {
    const dropdown = document.getElementById('user-dropdown-menu');
    if (dropdown) {
        dropdown.classList.remove('open');
        document.removeEventListener('click', closeDropdownOnClickOutside);
    }
}

/**
 * Close dropdown when clicking outside
 */
function closeDropdownOnClickOutside(e) {
    const dropdown = document.getElementById('user-dropdown-menu');
    const userProfile = document.querySelector('.user-profile');
    
    if (dropdown && !dropdown.contains(e.target) && !userProfile?.contains(e.target)) {
        closeUserDropdown();
    }
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
    const loginButtons = document.querySelectorAll('.nav-links a.get-started-btn, .nav-right a.get-started-btn');
    loginButtons.forEach(btn => {
        btn.style.visibility = 'hidden';
        btn.style.opacity = '0';
    });

    // Show user profile section in navbar with dropdown (desktop)
    const navRight = document.querySelector('.nav-right');
    if (navRight) {
        navRight.innerHTML = `
            <div class="user-profile" onclick="toggleUserDropdown()">
                <img src="${userData.avatar}" alt="${userData.username}" class="user-avatar" title="${userData.username}">
            </div>
        `;
    }

    // Update mobile menu (hide login button, show profile menu)
    const mobileUserSection = document.getElementById('mobile-user-section');
    const mobileProfileMenu = document.getElementById('mobile-profile-menu');
    
    if (mobileUserSection && mobileProfileMenu) {
        mobileUserSection.style.display = 'none';
        mobileProfileMenu.style.display = 'flex';
    }

    // Update mobile button to show profile picture instead of hamburger
    const mobileMenuIcon = document.getElementById('mobile-menu-icon');
    const mobileProfilePic = document.getElementById('mobile-profile-pic');
    const mobileProfileImg = document.getElementById('mobile-profile-img');
    
    if (mobileMenuIcon && mobileProfilePic && mobileProfileImg) {
        mobileMenuIcon.style.display = 'none';
        mobileProfilePic.style.display = 'flex';
        mobileProfileImg.src = userData.avatar;
    }

    hideLoginDialog();
}

/**
 * Update UI after logout
 */
function updateUIAfterLogout() {
    // Show the "Login to GitHub" button again with smooth transition
    const loginButtons = document.querySelectorAll('.nav-links a.get-started-btn, .nav-right a.get-started-btn');
    loginButtons.forEach(btn => {
        btn.style.visibility = 'visible';
        btn.style.opacity = '1';
    });

    // Hide user profile section (desktop)
    const navRight = document.querySelector('.nav-right');
    if (navRight) {
        navRight.innerHTML = '';
    }

    // Update mobile menu (show login button, hide profile menu)
    const mobileUserSection = document.getElementById('mobile-user-section');
    const mobileProfileMenu = document.getElementById('mobile-profile-menu');
    
    if (mobileUserSection && mobileProfileMenu) {
        mobileUserSection.style.display = 'block';
        mobileProfileMenu.style.display = 'none';
    }

    // Update mobile button to show hamburger menu instead of profile picture
    const mobileMenuIcon = document.getElementById('mobile-menu-icon');
    const mobileProfilePic = document.getElementById('mobile-profile-pic');
    
    if (mobileMenuIcon && mobileProfilePic) {
        mobileMenuIcon.style.display = 'flex';
        mobileProfilePic.style.display = 'none';
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
    } else {
        // Show login buttons if not logged in
        const loginButtons = document.querySelectorAll('.nav-links a.get-started-btn, .nav-right a.get-started-btn');
        loginButtons.forEach(btn => {
            btn.style.visibility = 'visible';
            btn.style.opacity = '1';
        });
    }

    // Add event listeners for mobile menu
    const mobileNavLinks = document.querySelectorAll('.mobile-nav-link');
    mobileNavLinks.forEach(link => {
        link.addEventListener('click', closeMobileMenu);
    });

    const mobileProfileLinks = document.querySelectorAll('.mobile-profile-link');
    mobileProfileLinks.forEach(link => {
        // Don't close for logout button since it opens a confirmation dialog
        if (!link.classList.contains('mobile-logout-btn')) {
            link.addEventListener('click', closeMobileMenu);
        }
    });
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
