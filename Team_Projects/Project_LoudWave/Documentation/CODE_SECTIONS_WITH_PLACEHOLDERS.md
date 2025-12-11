# GitHub OAuth - Code Sections with Highlighted Placeholders

## FILE: `github-auth.js`

### SECTION 1: Configuration (Lines 1-7)

```javascript
// ============================================
// GITHUB OAUTH CONFIGURATION
// ============================================
// TODO: Replace these placeholders with your GitHub OAuth app credentials
const GITHUB_CLIENT_ID = 'YOUR_GITHUB_CLIENT_ID_HERE';         // ← PLACEHOLDER #1
const GITHUB_REDIRECT_URI = 'YOUR_REDIRECT_URI_HERE';          // ← PLACEHOLDER #2
const GITHUB_SCOPES = 'user:email repo workflow';              // (no placeholder - leave as is)
```

**Action Required:**
- Replace `YOUR_GITHUB_CLIENT_ID_HERE` with your actual Client ID
- Replace `YOUR_REDIRECT_URI_HERE` with your actual redirect URL

**Examples:**
```javascript
const GITHUB_CLIENT_ID = 'Ov23lic5L6m7n8o9p0q1r2';
const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html';
```

---

### SECTION 2: Token Exchange (Lines 48-71)

```javascript
/**
 * Exchange authorization code for access token
 * This should be called from your backend
 * TODO: You need a backend endpoint that:
 * 1. Takes the authorization code
 * 2. Exchanges it for an access token using your GitHub Client Secret
 * 3. Returns the access token to the frontend
 * 
 * Backend endpoint format:
 * POST /api/github/callback
 * Body: { code: string }
 * Response: { access_token: string }
 */
async function exchangeCodeForToken(code) {
    try {
        // TODO: Replace 'YOUR_BACKEND_URL' with your actual backend URL ← PLACEHOLDER #3
        const response = await fetch('YOUR_BACKEND_URL/api/github/callback', {
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
```

**Action Required:**
- Replace `YOUR_BACKEND_URL` with your backend URL
- Backend must handle `POST /api/github/callback`
- Backend must exchange code for token using Client Secret
- Backend returns `{ access_token: string }`

**Examples:**
```javascript
// Development:
const response = await fetch('http://localhost:5000/api/github/callback', {

// Production:
const response = await fetch('https://api.yourdomain.com/api/github/callback', {
```

---

### SECTION 3: Repository Clone (Lines 369-391)

```javascript
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
        // TODO: Implement backend endpoint for cloning ← PLACEHOLDER #5 (optional)
        // TODO: Backend should handle: git clone, authentication, file system access
        const response = await fetch('YOUR_BACKEND_URL/api/repo/clone', {
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
```

**Action Required (Optional):**
- Same `YOUR_BACKEND_URL` as PLACEHOLDER #3
- Backend must create `/api/repo/clone` endpoint
- Endpoint receives: `{ repoUrl: string }`
- Endpoint performs actual git clone operation

---

### SECTION 4: Workflow Start (Lines 392-416)

```javascript
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
                body: JSON.stringify({ ref: 'main' }) // TODO: Adjust ref as needed ← PLACEHOLDER #6
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
```

**Action Required (Optional):**
- Provide actual values when calling function:
  - `owner`: Your GitHub username or organization
  - `repo`: Repository name
  - `workflowId`: Workflow file name or ID

**Example Usage:**
```javascript
// When you call the function:
startWorkflow('GCC-GRH', 'LoudWave', 'main.yml');

// Parameters:
// 'GCC-GRH' = owner (your GitHub org)
// 'LoudWave' = repo (repository name)
// 'main.yml' = workflowId (workflow file name from .github/workflows/)
```

---

### SECTION 5: Workflow Stop (Lines 417-442)

```javascript
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
```

**Action Required (Optional):**
- Provide actual values when calling function:
  - `owner`: GitHub username or organization
  - `repo`: Repository name
  - `runId`: Workflow run ID (from GitHub API response)

**Example Usage:**
```javascript
// When you call the function:
stopWorkflow('GCC-GRH', 'LoudWave', 12345);

// Parameters:
// 'GCC-GRH' = owner
// 'LoudWave' = repo
// 12345 = runId (the specific workflow run to cancel)
```

---

## FILE: `index.html`

### CHANGE 1: Add Script Reference (Line 9)

**Before:**
```html
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LoudWave | Desktop On The Cloud</title>
    <link rel="stylesheet" href="critical.css">
    <link rel="stylesheet" href="styles.css">
    <link rel="stylesheet" href="getting-started.css">
    <script src="script.js" defer></script>
</head>
```

**After:**
```html
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LoudWave | Desktop On The Cloud</title>
    <link rel="stylesheet" href="critical.css">
    <link rel="stylesheet" href="styles.css">
    <link rel="stylesheet" href="getting-started.css">
    <script src="script.js" defer></script>
    <script src="github-auth.js" defer></script>    ← ADDED
</head>
```

---

### CHANGE 2: Login Button Handler (Navbar Section)

**Before:**
```html
<div class="nav-links">
    <a href="#home" class="active">Home</a>
    <a href="about.html">About Us</a>
    <a href="#downloads">Downloads</a>
    <a href="https://github.com/GCC-GRH" target="_blank">Github</a>
    <a href="https://github.com/login" class="get-started-btn mobile-only" target="_blank">Login to GitHub</a>
</div>
</div>
<div class="nav-right desktop-only">
    <a href="https://github.com/login" class="get-started-btn" target="_blank">Login to GitHub</a>
</div>
```

**After:**
```html
<div class="nav-links">
    <a href="#home" class="active">Home</a>
    <a href="about.html">About Us</a>
    <a href="#downloads">Downloads</a>
    <a href="https://github.com/GCC-GRH" target="_blank">Github</a>
    <a href="javascript:initGitHubLogin()" class="get-started-btn mobile-only">Login to GitHub</a>
</div>
</div>
<div class="nav-right desktop-only">
    <a href="javascript:initGitHubLogin()" class="get-started-btn">Login to GitHub</a>
</div>
```

**Changes:**
- ✅ `href="https://github.com/login"` → `href="javascript:initGitHubLogin()"`
- ✅ Removed `target="_blank"`

---

### CHANGE 3: Login Dialog HTML (End of Body)

**Added Before `</body>`:**
```html
    <!-- GitHub OAuth Login Dialog -->
    <div id="login-dialog" class="login-dialog">
        <div class="login-dialog-content">
            <div class="login-spinner"></div>
            <p class="login-text">Logging you in!</p>
        </div>
    </div>

</body>
```

---

## FILE: `styles.css`

### ADDITION: Login Dialog Styles (110 lines added at end)

**Lines Added Before Final `}` or at End:**

```css
/* ============================================ */
/* GITHUB OAUTH LOGIN DIALOG STYLES */
/* ============================================ */

#login-dialog {
    display: none;
    position: fixed;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    background: rgba(10, 10, 15, 0.95);
    backdrop-filter: blur(10px);
    -webkit-backdrop-filter: blur(10px);
    z-index: 9999;
    justify-content: center;
    align-items: center;
    pointer-events: auto;
}

.login-dialog-content {
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 2rem;
}

.login-spinner {
    width: 60px;
    height: 60px;
    border: 4px solid rgba(111, 76, 255, 0.2);
    border-top: 4px solid #6F4CFF;
    border-radius: 50%;
    animation: login-spin 1s linear infinite;
}

@keyframes login-spin {
    to {
        transform: rotate(360deg);
    }
}

.login-text {
    font-size: 1.5rem;
    font-weight: 600;
    color: #FFFFFF;
    letter-spacing: 0.5px;
}

/* ============================================ */
/* USER PROFILE SECTION (Navbar) */
/* ============================================ */

.nav-right {
    display: flex;
    align-items: center;
    gap: 1rem;
}

.user-profile {
    display: flex;
    align-items: center;
    gap: 0.75rem;
    padding: 0.5rem 1rem;
    background: rgba(111, 76, 255, 0.1);
    border: 1px solid rgba(111, 76, 255, 0.3);
    border-radius: 50px;
    cursor: pointer;
    transition: all 0.3s ease;
}

.user-profile:hover {
    background: rgba(111, 76, 255, 0.15);
    border-color: rgba(111, 76, 255, 0.5);
}

.user-avatar {
    width: 32px;
    height: 32px;
    border-radius: 50%;
    border: 2px solid rgba(111, 76, 255, 0.5);
    object-fit: cover;
    transition: transform 0.2s ease;
}

.user-avatar:hover {
    transform: scale(1.05);
}

.user-name {
    font-size: 0.9rem;
    font-weight: 500;
    color: #FFFFFF;
}

.logout-btn {
    background: none;
    border: none;
    color: #FF6A84;
    cursor: pointer;
    padding: 0;
    display: flex;
    align-items: center;
    justify-content: center;
    transition: all 0.2s ease;
    margin-left: 0.5rem;
}

.logout-btn:hover {
    color: #FF8FA1;
    transform: scale(1.1);
}

.logout-btn svg {
    width: 16px;
    height: 16px;
}

/* Mobile responsive for user profile */
@media (max-width: 768px) {
    .user-profile {
        padding: 0.4rem 0.8rem;
    }

    .user-avatar {
        width: 28px;
        height: 28px;
    }

    .user-name {
        font-size: 0.85rem;
    }
}

@media (max-width: 480px) {
    .user-profile {
        gap: 0.5rem;
    }

    .user-name {
        display: none;
    }

    .login-text {
        font-size: 1.2rem;
    }

    .login-spinner {
        width: 50px;
        height: 50px;
    }
}
```

---

## BACKEND: `app.js` (Node.js)

### Token Exchange Endpoint

**File: `app.js` (Backend)**

```javascript
// ============================================
// ENVIRONMENT VARIABLES
// ============================================
// TODO: Create a .env file with:
/*
GITHUB_CLIENT_ID=YOUR_GITHUB_CLIENT_ID_HERE              ← PLACEHOLDER
GITHUB_CLIENT_SECRET=YOUR_GITHUB_CLIENT_SECRET_HERE      ← PLACEHOLDER
GITHUB_REDIRECT_URI=YOUR_REDIRECT_URI_HERE               ← PLACEHOLDER
PORT=5000
*/

// ============================================
// TOKEN EXCHANGE ENDPOINT
// ============================================

/**
 * POST /api/github/callback
 * Exchanges GitHub authorization code for access token
 * 
 * Request body: { code: string }
 * Response: { access_token: string }
 */
app.post('/api/github/callback', async (req, res) => {
    const { code } = req.body;

    if (!code) {
        return res.status(400).json({ error: 'Authorization code is required' });
    }

    try {
        // Exchange authorization code for access token
        const response = await axios.post(
            'https://github.com/login/oauth/access_token',
            {
                client_id: process.env.GITHUB_CLIENT_ID,           // ← From .env
                client_secret: process.env.GITHUB_CLIENT_SECRET,   // ← From .env
                code: code,
                redirect_uri: process.env.GITHUB_REDIRECT_URI      // ← From .env
            },
            {
                headers: {
                    Accept: 'application/json'
                }
            }
        );

        if (response.data.error) {
            return res.status(401).json({ 
                error: response.data.error_description || 'Failed to exchange code for token'
            });
        }

        const accessToken = response.data.access_token;

        // Return access token to frontend
        return res.json({ access_token: accessToken });

    } catch (error) {
        console.error('Token exchange error:', error.message);
        return res.status(500).json({ error: 'Internal server error' });
    }
});
```

---

## Backend `.env` File

```env
# GitHub OAuth Configuration
GITHUB_CLIENT_ID=YOUR_GITHUB_CLIENT_ID_HERE              ← PLACEHOLDER #4a
GITHUB_CLIENT_SECRET=YOUR_GITHUB_CLIENT_SECRET_HERE      ← PLACEHOLDER #4b
GITHUB_REDIRECT_URI=YOUR_REDIRECT_URI_HERE               ← PLACEHOLDER #4c

# Server Configuration
PORT=5000
NODE_ENV=development
```

**Get These Values From:**
1. **GITHUB_CLIENT_ID**: https://github.com/settings/developers → Your App → Client ID
2. **GITHUB_CLIENT_SECRET**: https://github.com/settings/developers → Your App → Client Secret
3. **GITHUB_REDIRECT_URI**: Same as frontend `GITHUB_REDIRECT_URI`

---

## Summary Table

| # | Placeholder | File | Location | Value |
|---|-------------|------|----------|-------|
| 1 | CLIENT_ID | github-auth.js | Line 5 | Your Client ID |
| 2 | REDIRECT_URI | github-auth.js | Line 6 | Your callback URL |
| 3 | BACKEND_URL | github-auth.js | Line 57 | Your backend URL |
| 4a | CLIENT_ID | .env (backend) | - | Same as #1 |
| 4b | CLIENT_SECRET | .env (backend) | - | GitHub secret |
| 4c | REDIRECT_URI | .env (backend) | - | Same as #2 |
| 5 | BACKEND_URL | github-auth.js | Line 377 | Same as #3 (optional) |
| 6 | WORKFLOW_ID | github-auth.js | Line 404 | When calling function |
| 7 | RUN_ID | github-auth.js | Line 430 | When calling function |

---

All placeholders are clearly marked with `TODO` comments in the code!

