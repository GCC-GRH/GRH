# Backend Implementation Guide - GitHub OAuth Token Exchange

## Overview
Your backend needs to handle the token exchange process since the GitHub Client Secret must never be exposed to the frontend.

---

## Node.js + Express Implementation

### Setup
```bash
npm install express cors dotenv axios
```

### Backend Code

```javascript
// app.js or server.js
const express = require('express');
const cors = require('cors');
const axios = require('axios');
require('dotenv').config();

const app = express();

app.use(cors());
app.use(express.json());

// ============================================
// ENVIRONMENT VARIABLES
// ============================================
// TODO: Create a .env file with:
/*
GITHUB_CLIENT_ID=YOUR_GITHUB_CLIENT_ID_HERE
GITHUB_CLIENT_SECRET=YOUR_GITHUB_CLIENT_SECRET_HERE
GITHUB_REDIRECT_URI=YOUR_REDIRECT_URI_HERE
PORT=5000
*/

const GITHUB_CLIENT_ID = process.env.GITHUB_CLIENT_ID;
const GITHUB_CLIENT_SECRET = process.env.GITHUB_CLIENT_SECRET;
const GITHUB_REDIRECT_URI = process.env.GITHUB_REDIRECT_URI;

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
                client_id: GITHUB_CLIENT_ID,
                client_secret: GITHUB_CLIENT_SECRET,
                code: code,
                redirect_uri: GITHUB_REDIRECT_URI
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

// ============================================
// REPOSITORY CLONING ENDPOINT (Optional)
// ============================================

/**
 * POST /api/repo/clone
 * Clones a GitHub repository
 * 
 * Request headers: Authorization: Bearer {accessToken}
 * Request body: { repoUrl: string }
 * Response: { success: boolean, message: string }
 */
app.post('/api/repo/clone', async (req, res) => {
    const { repoUrl } = req.body;
    const authHeader = req.headers.authorization;
    const accessToken = authHeader?.replace('Bearer ', '');

    if (!accessToken) {
        return res.status(401).json({ error: 'Access token is required' });
    }

    if (!repoUrl) {
        return res.status(400).json({ error: 'Repository URL is required' });
    }

    try {
        // TODO: Implement actual git cloning logic
        // This is a simplified example
        
        // Validate access token by fetching user
        const userResponse = await axios.get('https://api.github.com/user', {
            headers: {
                Authorization: `Bearer ${accessToken}`
            }
        });

        // TODO: Use a git library like nodegit or call git CLI
        // For now, just return success placeholder
        
        return res.json({ 
            success: true, 
            message: 'Repository cloning initiated',
            clonedBy: userResponse.data.login
        });

    } catch (error) {
        console.error('Clone error:', error.message);
        return res.status(500).json({ error: 'Failed to clone repository' });
    }
});

// ============================================
// WORKFLOW MANAGEMENT ENDPOINTS (Optional)
// ============================================

/**
 * POST /api/workflow/start
 * Starts a GitHub Actions workflow
 */
app.post('/api/workflow/start', async (req, res) => {
    const { owner, repo, workflowId } = req.body;
    const authHeader = req.headers.authorization;
    const accessToken = authHeader?.replace('Bearer ', '');

    if (!accessToken) {
        return res.status(401).json({ error: 'Access token is required' });
    }

    try {
        const response = await axios.post(
            `https://api.github.com/repos/${owner}/${repo}/actions/workflows/${workflowId}/dispatches`,
            { ref: 'main' },
            {
                headers: {
                    Authorization: `Bearer ${accessToken}`,
                    Accept: 'application/vnd.github.v3+json'
                }
            }
        );

        return res.json({ success: true, message: 'Workflow started' });

    } catch (error) {
        console.error('Workflow start error:', error.message);
        return res.status(error.response?.status || 500).json({ 
            error: error.message 
        });
    }
});

/**
 * POST /api/workflow/stop
 * Stops a GitHub Actions workflow run
 */
app.post('/api/workflow/stop', async (req, res) => {
    const { owner, repo, runId } = req.body;
    const authHeader = req.headers.authorization;
    const accessToken = authHeader?.replace('Bearer ', '');

    if (!accessToken) {
        return res.status(401).json({ error: 'Access token is required' });
    }

    try {
        const response = await axios.post(
            `https://api.github.com/repos/${owner}/${repo}/actions/runs/${runId}/cancel`,
            {},
            {
                headers: {
                    Authorization: `Bearer ${accessToken}`,
                    Accept: 'application/vnd.github.v3+json'
                }
            }
        );

        return res.json({ success: true, message: 'Workflow stopped' });

    } catch (error) {
        console.error('Workflow stop error:', error.message);
        return res.status(error.response?.status || 500).json({ 
            error: error.message 
        });
    }
});

// ============================================
// START SERVER
// ============================================

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
    console.log(`Backend server running on http://localhost:${PORT}`);
});
```

### Environment File (.env)
```
GITHUB_CLIENT_ID=Ov23li1a2b3c4d5e6f7g
GITHUB_CLIENT_SECRET=your_client_secret_here_keep_secret
GITHUB_REDIRECT_URI=http://localhost:3000/callback.html
PORT=5000
```

### Run Backend
```bash
node app.js
```

---

## Python + Flask Implementation

### Setup
```bash
pip install flask flask-cors python-dotenv requests
```

### Backend Code

```python
# app.py
from flask import Flask, request, jsonify
from flask_cors import CORS
import requests
import os
from dotenv import load_dotenv

load_dotenv()

app = Flask(__name__)
CORS(app)

# Environment variables
GITHUB_CLIENT_ID = os.getenv('GITHUB_CLIENT_ID')
GITHUB_CLIENT_SECRET = os.getenv('GITHUB_CLIENT_SECRET')
GITHUB_REDIRECT_URI = os.getenv('GITHUB_REDIRECT_URI')

# ============================================
# TOKEN EXCHANGE ENDPOINT
# ============================================

@app.route('/api/github/callback', methods=['POST'])
def github_callback():
    """Exchange GitHub authorization code for access token"""
    
    data = request.get_json()
    code = data.get('code')

    if not code:
        return jsonify({'error': 'Authorization code is required'}), 400

    try:
        # Exchange code for access token
        response = requests.post(
            'https://github.com/login/oauth/access_token',
            json={
                'client_id': GITHUB_CLIENT_ID,
                'client_secret': GITHUB_CLIENT_SECRET,
                'code': code,
                'redirect_uri': GITHUB_REDIRECT_URI
            },
            headers={'Accept': 'application/json'}
        )

        if response.status_code != 200:
            return jsonify({'error': 'Failed to exchange code for token'}), 401

        response_data = response.json()

        if 'error' in response_data:
            return jsonify({'error': response_data['error_description']}), 401

        access_token = response_data.get('access_token')

        return jsonify({'access_token': access_token}), 200

    except Exception as e:
        print(f'Token exchange error: {str(e)}')
        return jsonify({'error': 'Internal server error'}), 500

# ============================================
# REPOSITORY CLONING ENDPOINT (Optional)
# ============================================

@app.route('/api/repo/clone', methods=['POST'])
def clone_repo():
    """Clone a GitHub repository"""
    
    auth_header = request.headers.get('Authorization', '')
    access_token = auth_header.replace('Bearer ', '')

    if not access_token:
        return jsonify({'error': 'Access token is required'}), 401

    data = request.get_json()
    repo_url = data.get('repoUrl')

    if not repo_url:
        return jsonify({'error': 'Repository URL is required'}), 400

    try:
        # Validate token by fetching user
        user_response = requests.get(
            'https://api.github.com/user',
            headers={'Authorization': f'Bearer {access_token}'}
        )

        if user_response.status_code != 200:
            return jsonify({'error': 'Invalid access token'}), 401

        user_data = user_response.json()

        # TODO: Implement actual git cloning logic
        # Could use subprocess.run(['git', 'clone', repo_url]) or gitpython library

        return jsonify({
            'success': True,
            'message': 'Repository cloning initiated',
            'cloned_by': user_data['login']
        }), 200

    except Exception as e:
        print(f'Clone error: {str(e)}')
        return jsonify({'error': 'Failed to clone repository'}), 500

# ============================================
# START SERVER
# ============================================

if __name__ == '__main__':
    PORT = os.getenv('PORT', 5000)
    app.run(debug=True, port=PORT)
```

### Environment File (.env)
```
GITHUB_CLIENT_ID=Ov23li1a2b3c4d5e6f7g
GITHUB_CLIENT_SECRET=your_client_secret_here_keep_secret
GITHUB_REDIRECT_URI=http://localhost:3000/callback.html
PORT=5000
```

### Run Backend
```bash
python app.py
```

---

## Important Points

1. **Client Secret Security**: Never expose your GitHub Client Secret in frontend code
2. **CORS Configuration**: Make sure CORS is properly configured for your frontend domain
3. **Token Storage**: Consider implementing token refresh mechanisms for long-lived sessions
4. **Error Handling**: Implement proper error handling and logging
5. **Rate Limiting**: GitHub API has rate limits - implement rate limiting on your backend
6. **HTTPS**: Use HTTPS in production for secure token transmission

---

## Testing the Backend

### Using cURL

```bash
# Test token exchange
curl -X POST http://localhost:5000/api/github/callback \
  -H "Content-Type: application/json" \
  -d '{"code":"provided_by_github"}'

# Test with access token
curl -X POST http://localhost:5000/api/repo/clone \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer your_access_token" \
  -d '{"repoUrl":"https://github.com/user/repo"}'
```

---

## Update Frontend Config

Once your backend is running, update `github-auth.js`:

```javascript
const GITHUB_CLIENT_ID = 'YOUR_GITHUB_CLIENT_ID';
const GITHUB_REDIRECT_URI = 'http://localhost:3000/callback.html'; // or your domain
// Change in exchangeCodeForToken function:
const response = await fetch('http://localhost:5000/api/github/callback', {
    // ... rest of code
});
```

