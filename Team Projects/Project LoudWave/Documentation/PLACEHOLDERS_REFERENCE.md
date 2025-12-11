# GitHub OAuth Credentials - Placeholder Locations

## Summary of All Placeholders to Fill

This document shows EXACTLY where you need to add your GitHub credentials and backend URL.

---

## PLACEHOLDER #1: GitHub Client ID

### File: `github-auth.js`
### Line: 5
### Current Code:
```javascript
const GITHUB_CLIENT_ID = 'YOUR_GITHUB_CLIENT_ID_HERE';
```

### What to Replace:
```
YOUR_GITHUB_CLIENT_ID_HERE
```

### With:
```
Your actual GitHub Client ID (looks like: Ov23li1a2b3c4d5e6f7g)
```

### Example:
```javascript
const GITHUB_CLIENT_ID = 'Ov23lic5L6m7n8o9p0q1r2';
```

### Where to Get It:
1. Go to https://github.com/settings/developers
2. Click on your OAuth App
3. Copy the "Client ID" value

---

## PLACEHOLDER #2: GitHub Redirect URI

### File: `github-auth.js`
### Line: 6
### Current Code:
```javascript
const GITHUB_REDIRECT_URI = 'YOUR_REDIRECT_URI_HERE';
```

### What to Replace:
```
YOUR_REDIRECT_URI_HERE
```

### With:
```
Your exact redirect URL (must match GitHub OAuth App settings)
```

### Examples:
**Development:**
```javascript
const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html';
```

**Production:**
```javascript
const GITHUB_REDIRECT_URI = 'https://yourdomain.com/callback.html';
```

### Important Notes:
- Must be EXACT match with GitHub OAuth App settings
- Must include the domain AND `/callback.html`
- Must include protocol (`http://` or `https://`)
- Different for dev vs production

### Where to Set It:
1. Go to https://github.com/settings/developers
2. Click on your OAuth App
3. Find "Authorization callback URL"
4. Must match exactly

---

## PLACEHOLDER #3: Backend URL

### File: `github-auth.js`
### Line: 57
### Current Code:
```javascript
const response = await fetch('YOUR_BACKEND_URL/api/github/callback', {
```

### What to Replace:
```
YOUR_BACKEND_URL
```

### With:
```
Your backend server URL
```

### Examples:
**Development:**
```javascript
const response = await fetch('http://localhost:5000/api/github/callback', {
```

**Production:**
```javascript
const response = await fetch('https://api.yourdomain.com/api/github/callback', {
```

### Important Notes:
- Include the protocol (`http://` or `https://`)
- Do NOT include `/callback.html` - that's on the frontend
- Your backend must handle: `POST /api/github/callback`
- Backend uses your **Client Secret** (never expose this)

### Context (Lines 51-65):
This is inside the `exchangeCodeForToken()` function. The complete function:

```javascript
async function exchangeCodeForToken(code) {
    try {
        // YOUR_BACKEND_URL goes here ↓
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

---

## PLACEHOLDER #4: GitHub Client Secret (BACKEND ONLY)

### NOT IN FRONTEND CODE

### File: Backend `.env` file
### Location: Your backend project directory
### Example:
```
GITHUB_CLIENT_ID=Ov23li1a2b3c4d5e6f7g
GITHUB_CLIENT_SECRET=your_secret_here_keep_absolutely_secret
GITHUB_REDIRECT_URI=http://localhost:3000/callback.html
PORT=5000
```

### ⚠️ CRITICAL: NEVER put Client Secret in frontend code

---

## PLACEHOLDER #5: Repository Clone Endpoint (Optional)

### File: `github-auth.js`
### Lines: 372-390 (Function: `cloneRepository()`)
### Current Code:
```javascript
const response = await fetch('YOUR_BACKEND_URL/api/repo/clone', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'Authorization': `Bearer ${accessToken}`
    },
    body: JSON.stringify({ repoUrl })
});
```

### What to Replace:
```
YOUR_BACKEND_URL
```

### With:
Same backend URL as Placeholder #3

### Example:
```javascript
const response = await fetch('http://localhost:5000/api/repo/clone', {
```

---

## PLACEHOLDER #6: Workflow Start Endpoint (Optional)

### File: `github-auth.js`
### Lines: 392-410 (Function: `startWorkflow()`)
### Current Code:
```javascript
async function startWorkflow(owner, repo, workflowId) {
    const accessToken = getAccessToken();
    // ...
    const response = await fetch(
        `https://api.github.com/repos/${owner}/${repo}/actions/workflows/${workflowId}/dispatches`,
        // ... uses GitHub API directly, no placeholder needed
    );
}
```

### What to Replace:
You need to provide actual values when calling the function:

```javascript
// Replace with your actual values:
startWorkflow('GCC-GRH', 'LoudWave', 'main.yml');
//           ↑ owner    ↑ repo       ↑ workflow file name
```

### Parameters:
- `owner`: GitHub username or organization (e.g., `GCC-GRH`)
- `repo`: Repository name (e.g., `LoudWave`)
- `workflowId`: Workflow file name or ID (e.g., `main.yml`)

---

## PLACEHOLDER #7: Workflow Stop Endpoint (Optional)

### File: `github-auth.js`
### Lines: 418-440 (Function: `stopWorkflow()`)

Same as Placeholder #6 - provide actual values when calling:

```javascript
stopWorkflow('GCC-GRH', 'LoudWave', 12345);
//           ↑ owner    ↑ repo       ↑ run ID (from GitHub API response)
```

---

## Quick Checklist

Before deploying, fill in these placeholders:

### Frontend (`github-auth.js`):
- [ ] Line 5: `GITHUB_CLIENT_ID` = `'Ov23...'`
- [ ] Line 6: `GITHUB_REDIRECT_URI` = `'http://localhost:3000/callback.html'`
- [ ] Line 57: `YOUR_BACKEND_URL` = `'http://localhost:5000'`
- [ ] Line 377 & 423: Same backend URL for optional endpoints

### Backend (`.env`):
- [ ] `GITHUB_CLIENT_ID` = Same as frontend
- [ ] `GITHUB_CLIENT_SECRET` = From GitHub OAuth App settings
- [ ] `GITHUB_REDIRECT_URI` = Same as frontend
- [ ] `PORT` = Your backend port

### Verification:
- [ ] Can access GitHub at https://github.com/settings/developers
- [ ] OAuth App exists with registered credentials
- [ ] Backend server is running and accessible
- [ ] All URLs match exactly (protocol, domain, path)
- [ ] No typos in Client ID

---

## Environment Variables Reference

### Development

**Frontend** (`github-auth.js`):
```javascript
const GITHUB_CLIENT_ID = 'Ov23li1a2b3c4d5e6f7g';
const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html';
// In exchangeCodeForToken():
const response = await fetch('http://localhost:5000/api/github/callback', {
```

**Backend** (`.env`):
```
GITHUB_CLIENT_ID=Ov23li1a2b3c4d5e6f7g
GITHUB_CLIENT_SECRET=github_pat_abc123def456ghi789jkl012mnopqrs
GITHUB_REDIRECT_URI=http://localhost:3000/callback.html
PORT=5000
```

### Production

**Frontend** (`github-auth.js`):
```javascript
const GITHUB_CLIENT_ID = 'Ov23li1a2b3c4d5e6f7g';
const GITHUB_REDIRECT_URI = 'https://loudwave.com/callback.html';
// In exchangeCodeForToken():
const response = await fetch('https://api.loudwave.com/api/github/callback', {
```

**Backend** (`.env`):
```
GITHUB_CLIENT_ID=Ov23li1a2b3c4d5e6f7g
GITHUB_CLIENT_SECRET=github_pat_abc123def456ghi789jkl012mnopqrs
GITHUB_REDIRECT_URI=https://loudwave.com/callback.html
PORT=443
```

---

## Common Mistakes to Avoid

❌ **Wrong**: `const GITHUB_CLIENT_ID = 'YOUR_GITHUB_CLIENT_ID_HERE';`
✅ **Correct**: `const GITHUB_CLIENT_ID = 'Ov23li1a2b3c4d5e6f7g';`

❌ **Wrong**: `const GITHUB_REDIRECT_URI = 'callback.html';`
✅ **Correct**: `const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html';`

❌ **Wrong**: `const response = await fetch('localhost:5000/api/github/callback', {`
✅ **Correct**: `const response = await fetch('http://localhost:5000/api/github/callback', {`

❌ **Wrong**: Putting Client Secret in frontend code
✅ **Correct**: Client Secret only in backend `.env`

❌ **Wrong**: Redirect URI doesn't match GitHub OAuth App settings
✅ **Correct**: Exact match including protocol, domain, and path

---

## How to Test Each Placeholder

### Test Placeholder #1 & #2 (Client ID & Redirect URI)
```javascript
// In browser console:
console.log(GITHUB_CLIENT_ID);     // Should show your Client ID
console.log(GITHUB_REDIRECT_URI);  // Should show your redirect URL
```

### Test Placeholder #3 (Backend URL)
```bash
# In terminal, test your backend is running:
curl http://localhost:5000/

# Or for production:
curl https://api.yourdomain.com/
```

### Test Placeholder #4 (Client Secret)
```bash
# Check your backend .env file contains the secret:
echo $GITHUB_CLIENT_SECRET
# Should output your secret (not shown in code)
```

---

## Still Stuck?

Refer to the detailed guides:
- `GITHUB_OAUTH_SETUP.md` - Complete setup instructions
- `BACKEND_IMPLEMENTATION.md` - Backend code examples
- `UI_COMPONENTS_GUIDE.md` - UI reference

All files are in your project directory.

