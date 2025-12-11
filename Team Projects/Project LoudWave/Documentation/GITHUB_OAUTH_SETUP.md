# GitHub OAuth Integration Guide - LoudWave

## Overview
This guide explains where to configure your GitHub OAuth credentials and how the authentication flow works.

---

## 1. GitHub OAuth Setup

### Step 1: Create GitHub OAuth App
1. Go to https://github.com/settings/developers
2. Click "New OAuth App"
3. Fill in the details:
   - **Application name**: LoudWave
   - **Homepage URL**: Your website URL (e.g., `http://localhost:3000` for development)
   - **Authorization callback URL**: `http://localhost:3000/callback.html` (development) or your live domain equivalent
4. Click "Register application"
5. You'll see your credentials:
   - **Client ID** - Copy this
   - **Client Secret** - Copy this (keep this SECRET! Never expose in frontend)

---

## 2. Where to Add Credentials

### File: `github-auth.js` (Lines 3-5)

```javascript
// ============================================
// GITHUB OAUTH CONFIGURATION
// ============================================
// TODO: Replace these placeholders with your GitHub OAuth app credentials
const GITHUB_CLIENT_ID = 'YOUR_GITHUB_CLIENT_ID_HERE'; // ← ADD YOUR CLIENT ID HERE
const GITHUB_REDIRECT_URI = 'YOUR_REDIRECT_URI_HERE'; // ← ADD YOUR REDIRECT URI HERE
const GITHUB_SCOPES = 'user:email repo workflow'; // Leave as is (unless you need different scopes)
```

**Example:**
```javascript
const GITHUB_CLIENT_ID = 'Ov23li1a2b3c4d5e6f7g';
const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html';
const GITHUB_SCOPES = 'user:email repo workflow';
```

---

## 3. Backend URL Configuration

### File: `github-auth.js` (Lines 51-65)

This is where you need to set up your **BACKEND SERVER**. Your backend will:
1. Receive the authorization code from GitHub
2. Exchange it for an access token (using your Client Secret)
3. Return the access token to your frontend

```javascript
/**
 * Exchange authorization code for access token
 * This should be called from your backend
 * TODO: You need a backend endpoint that:
 * 1. Takes the authorization code
 * 2. Exchanges it for an access token using your GitHub Client Secret
 * 3. Returns the access token to the frontend
 */
async function exchangeCodeForToken(code) {
    try {
        // TODO: Replace 'YOUR_BACKEND_URL' with your actual backend URL
        const response = await fetch('YOUR_BACKEND_URL/api/github/callback', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ code })
        });
        // ... rest of code
    }
}
```

**Action Required:**
- Set up a backend server (Node.js, Python, etc.)
- Create endpoint: `POST /api/github/callback`
- Endpoint should accept `{ code: string }` 
- Exchange code for token using GitHub API with your Client Secret
- Return `{ access_token: string }`

**Example Backend Response:**
```json
{
  "access_token": "ghu_16C7e42F292c6912E7710c838347Ae178B4a"
}
```

---

## 4. Key Placeholder Locations

### 1. **GITHUB_CLIENT_ID** (Line 5 in github-auth.js)
- **What it is**: Public identifier for your app
- **Where to get**: GitHub Settings → Developer Settings → OAuth Apps → Your App → Client ID
- **Example**: `Ov23li1a2b3c4d5e6f7g`

### 2. **GITHUB_REDIRECT_URI** (Line 6 in github-auth.js)
- **What it is**: URL where GitHub redirects after user authenticates
- **Must match**: Exactly what you registered in GitHub OAuth App settings
- **Development**: `http://localhost:3000/callback.html`
- **Production**: `https://yourdomain.com/callback.html`

### 3. **GITHUB_CLIENT_SECRET** (NOT IN FRONTEND)
- **⚠️ IMPORTANT**: This must ONLY be stored on your backend server
- **NEVER put this in frontend code**
- **Your backend uses this to exchange code for token**
- **Where to get**: GitHub Settings → Developer Settings → OAuth Apps → Your App → Client Secret

### 4. **YOUR_BACKEND_URL** (Line 57 in github-auth.js)
- **What it is**: Your backend server address
- **Development**: `http://localhost:5000` (adjust port as needed)
- **Production**: `https://api.yourdomain.com`
- **Complete endpoint**: `YOUR_BACKEND_URL/api/github/callback`

### 5. **Repository Functions** (Lines 372-460 in github-auth.js)

These functions require specific GitHub repository information:

#### Clone Repository (Line 372)
```javascript
/**
 * Clone a repository
 * TODO: This needs backend support for actual cloning
 */
async function cloneRepository(repoUrl) {
    // TODO: Implement backend endpoint for cloning
    // Backend should handle: git clone, authentication, file system access
    const response = await fetch('YOUR_BACKEND_URL/api/repo/clone', {
        // ... config
    });
}
```

**Required Setup:**
- Create endpoint: `POST /api/repo/clone`
- Accept: `{ repoUrl: string }`
- Backend performs actual `git clone` operation

#### Start Workflow (Line 392)
```javascript
async function startWorkflow(owner, repo, workflowId) {
    const accessToken = getAccessToken();
    // ... existing code ...
    const response = await fetch(
        `https://api.github.com/repos/${owner}/${repo}/actions/workflows/${workflowId}/dispatches`,
        // ...
    );
}
```

**Required Parameters:**
- `owner`: GitHub username/org (e.g., `"GCC-GRH"`)
- `repo`: Repository name (e.g., `"LoudWave"`)
- `workflowId`: Workflow file name or ID (e.g., `"main.yml"` or ID number)

**Usage Example:**
```javascript
startWorkflow('GCC-GRH', 'LoudWave', 'main.yml');
```

#### Stop Workflow (Line 418)
```javascript
async function stopWorkflow(owner, repo, runId) {
    // ... similar setup ...
    const response = await fetch(
        `https://api.github.com/repos/${owner}/${repo}/actions/runs/${runId}/cancel`,
        // ...
    );
}
```

**Required Parameters:**
- `runId`: The specific run ID to cancel (integer)

---

## 5. OAuth Flow Diagram

```
1. User clicks "Login to GitHub" button
   ↓
2. Frontend calls initGitHubLogin()
   ↓
3. Shows loading dialog: "Logging you in!"
   ↓
4. Redirects to GitHub OAuth authorization page
   ↓
5. User authorizes on GitHub
   ↓
6. GitHub redirects to YOUR_REDIRECT_URI with authorization code
   ↓
7. callback.html loads and calls handleGitHubCallback()
   ↓
8. Frontend sends code to YOUR_BACKEND_URL/api/github/callback
   ↓
9. Backend exchanges code for access token using Client Secret
   ↓
10. Backend returns access token to frontend
   ↓
11. Frontend fetches user data from GitHub API
   ↓
12. Frontend saves user data to localStorage
   ↓
13. Login dialog closes, user profile shows in navbar
   ↓
14. Redirects to home page
```

---

## 6. File Structure Summary

```
project/
├── index.html              ← Updated with login dialog and auth script
├── callback.html           ← NEW - Handles OAuth redirect
├── about.html              ← May need to add login dialog here too
├── styles.css              ← Updated with login dialog + user profile CSS
├── getting-started.css     ← No changes needed
├── critical.css            ← No changes needed
├── script.js               ← No changes needed
└── github-auth.js          ← NEW - All OAuth logic and API calls
```

---

## 7. Testing Checklist

### Before Testing:
- [ ] Create GitHub OAuth App at https://github.com/settings/developers
- [ ] Get Client ID and Client Secret
- [ ] Copy Client ID to `GITHUB_CLIENT_ID` in `github-auth.js`
- [ ] Copy Redirect URI to `GITHUB_REDIRECT_URI` in `github-auth.js`
- [ ] Set up backend server with token exchange endpoint
- [ ] Update `YOUR_BACKEND_URL` in `github-auth.js`

### During Testing:
- [ ] Click "Login to GitHub" button in navbar
- [ ] Verify loading dialog appears with "Logging you in!" message
- [ ] Verify dialog blocks interaction with page (no clicks outside)
- [ ] Verify redirect to GitHub login page
- [ ] Verify redirect back to your site after auth
- [ ] Verify user profile shows in navbar (avatar + username)
- [ ] Verify logout button appears
- [ ] Verify logout clears session and shows login button again

### Common Issues:
- **"Redirect URI mismatch"** → Check your redirect URI matches GitHub settings exactly
- **"Invalid client ID"** → Copy the correct Client ID from GitHub settings
- **"Token exchange fails"** → Check your backend endpoint is accessible and returns token correctly
- **Dialog stays visible** → Check browser console for JavaScript errors

---

## 8. Security Notes

⚠️ **Important Security Considerations:**

1. **Client Secret**: 
   - Never store in frontend code
   - Only use on backend
   - Rotate if exposed

2. **Access Token**:
   - Currently stored in localStorage
   - Consider using httpOnly cookies or sessionStorage instead
   - Implement token refresh mechanism

3. **User Data**:
   - Review what data you're storing
   - Implement proper data privacy policies
   - Clear data on logout

4. **Scopes**:
   - Current: `user:email repo workflow`
   - `user:email` - Read user email
   - `repo` - Access to repositories and workflows
   - `workflow` - Read and write workflow access
   - Adjust scopes to minimum required

---

## 9. Next Steps

1. Create GitHub OAuth App
2. Set `GITHUB_CLIENT_ID` and `GITHUB_REDIRECT_URI` in `github-auth.js`
3. Build backend endpoint at `/api/github/callback` to exchange code for token
4. Test login flow
5. Update repository functions with your GitHub org/repo details
6. Deploy to production with production URLs

---

## 10. Reference Links

- GitHub OAuth Documentation: https://docs.github.com/en/developers/apps/building-oauth-apps
- GitHub API Reference: https://docs.github.com/en/rest
- GitHub Actions API: https://docs.github.com/en/rest/actions
- OAuth 2.0 Specification: https://tools.ietf.org/html/rfc6749

