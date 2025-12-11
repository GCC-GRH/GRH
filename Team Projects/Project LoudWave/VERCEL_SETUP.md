# Vercel OAuth Setup - Quick Steps

## ✅ What Was Done

Your code is now ready for Vercel! Here's what changed:

### 1. Created Vercel Serverless Function
**File:** `api/github/callback.js`
- Handles GitHub OAuth code exchange securely
- Uses `CLIENT_SECRET` from Vercel environment variables
- Returns access token to frontend

### 2. Updated `github-auth.js`
- Line 6: Fixed REDIRECT_URI to `https://loudwave.vercel.app/callback.html`
- Line 47: Now uses `/api/github/callback` (Vercel serverless function)
- Comments updated to reflect Vercel setup

---

## 📋 Steps to Deploy & Configure

### Step 1: Push Code to GitHub
```bash
git add .
git commit -m "Add GitHub OAuth with Vercel serverless function"
git push origin main
```

Vercel will automatically detect the changes and redeploy your site.

### Step 2: Add Environment Variables to Vercel

Go to **Vercel Dashboard** → Your Project → **Settings** → **Environment Variables**

Add these:
```
GITHUB_CLIENT_ID = Ov23liYLlWgff0wIqfML
GITHUB_CLIENT_SECRET = (your GitHub OAuth app Client Secret)
```

**Where to get Client Secret:**
1. Go to https://github.com/settings/developers
2. Click your OAuth App
3. Find "Client Secret" and copy it
4. Paste into Vercel environment variable

### Step 3: Update GitHub OAuth App Settings

Make sure your GitHub OAuth App has this **Authorization callback URL**:
```
https://loudwave.vercel.app/callback.html
```

**To verify/update:**
1. Go to https://github.com/settings/developers
2. Click your app
3. Check "Authorization callback URL" matches exactly above
4. If different, update it

### Step 4: Test

1. Visit your Vercel site: https://loudwave.vercel.app
2. Click "Login to GitHub"
3. Verify loading dialog appears
4. Authorize on GitHub
5. Should redirect back and show user profile
6. Avatar and username should display

---

## 🔒 Security - CLIENT SECRET Flow

```
Frontend (browser)
    ↓ Send authorization code
    ↓
Vercel Serverless Function (/api/github/callback.js)
    ↓ Has: CLIENT_ID + CLIENT_SECRET (from env vars)
    ↓
GitHub API
    ↓ Returns: ACCESS_TOKEN
    ↓
Back to Frontend (with token)
    ↓ Frontend can now use token for API calls
```

✅ **Client Secret stays safe** - Never leaves Vercel servers  
✅ **Not in frontend code** - Only in Vercel environment variables  
✅ **Not in GitHub** - Env vars kept private

---

## 📁 Project Structure

```
Project LoudWave/
├── api/
│   └── github/
│       └── callback.js ................... ✅ NEW (Vercel serverless)
├── index.html ............................ (unchanged)
├── github-auth.js ....................... (UPDATED - uses /api/github/callback)
├── callback.html ......................... (unchanged)
└── ... other files
```

---

## ✅ Quick Checklist

- [ ] Pushed code to GitHub
- [ ] Vercel automatically redeployed
- [ ] Added `GITHUB_CLIENT_ID` to Vercel env vars
- [ ] Added `GITHUB_CLIENT_SECRET` to Vercel env vars
- [ ] Verified GitHub OAuth App redirect URL matches
- [ ] Tested login on your site
- [ ] User profile displays after login
- [ ] Logout works correctly

---

## 🚀 You're All Set!

**Everything is ready to go.** Just:

1. Push to GitHub
2. Add environment variables to Vercel dashboard
3. Test your OAuth flow
4. Done! 🎉

---

## 🔗 Useful Links

- Your Vercel Dashboard: https://vercel.com/dashboard
- GitHub OAuth Apps: https://github.com/settings/developers
- Vercel Docs (API Routes): https://vercel.com/docs/concepts/functions/serverless-functions

---

## 🆘 Troubleshooting

**"Redirect URI mismatch" error?**
→ Make sure GitHub OAuth App has exact URL: `https://loudwave.vercel.app/callback.html`

**"Invalid client secret" error?**
→ Check you copied the secret correctly into Vercel env vars

**Dialog appears but doesn't redirect?**
→ Check browser console for errors

**User profile not showing?**
→ Check Vercel function logs to see if token exchange worked

---

**All set! Push your code and configure Vercel env vars, then you're live with GitHub OAuth! 🚀**

