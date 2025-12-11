// Vercel Serverless Function - GitHub OAuth Token Exchange
// This function securely exchanges the GitHub authorization code for an access token
// The CLIENT_SECRET is stored in Vercel environment variables and never exposed to frontend

export default async function handler(req, res) {
    // Only accept POST requests
    if (req.method !== 'POST') {
        return res.status(405).json({ error: 'Method not allowed' });
    }

    const { code } = req.body;

    // Validate that code is provided
    if (!code) {
        return res.status(400).json({ error: 'Authorization code is required' });
    }

    try {
        // Exchange authorization code for access token
        // ✅ CLIENT_SECRET is securely stored in Vercel environment variables
        const response = await fetch('https://github.com/login/oauth/access_token', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
                'Accept': 'application/json'
            },
            body: JSON.stringify({
                client_id: process.env.GITHUB_CLIENT_ID,           // From Vercel env
                client_secret: process.env.GITHUB_CLIENT_SECRET,   // ✅ SECRET - Safe here!
                code: code                                          // From frontend
            })
        });

        const data = await response.json();

        // Check if GitHub returned an error
        if (data.error) {
            console.error('GitHub OAuth error:', data.error_description);
            return res.status(400).json({ 
                error: data.error_description || 'Failed to exchange code for token' 
            });
        }

        // Success! Return the access token to frontend
        const accessToken = data.access_token;

        res.status(200).json({ access_token: accessToken });

    } catch (error) {
        console.error('Token exchange error:', error);
        res.status(500).json({ error: 'Internal server error during token exchange' });
    }
}
