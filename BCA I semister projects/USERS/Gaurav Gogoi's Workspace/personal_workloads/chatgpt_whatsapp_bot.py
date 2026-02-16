

import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import openai

# === CONFIG ===
OPENAI_API_KEY = "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"  # replace with your OpenAI API key
openai.api_key = OPENAI_API_KEY
GPT_TRIGGER = "gpt:"
YOUR_NAME = "0xethervoid0"  # must exactly match your WhatsApp contact name for yourself

# === WHATSAPP LAUNCH ===
options = uc.ChromeOptions()
options.user_data_dir = "C:/Users/babid/.whatsapp_session"
driver = uc.Chrome(options=options)

print("Launching WhatsApp Web...")
driver.get("https://web.whatsapp.com")
time.sleep(20)  # manual login or session restore

# === HELPER FUNCTION ===
def is_group_chat():
    return bool(driver.find_elements(By.XPATH, '//header//*[contains(@data-testid,"default-group")]'))

def is_msg_from_you(msg_elements):
    for e in msg_elements[::-1]:  # start from last
        try:
            parent = e.find_element(By.XPATH, '..')
            aria_label = parent.get_attribute("aria-label")
            if aria_label and YOUR_NAME.lower() in aria_label.lower():
                return True, e.text.strip()
        except:
            continue
    return False, ""

# === MAIN LOOP ===
print("Bot is running...")
last_handled = ""

while True:
    try:
        time.sleep(2)

        # Get all chat items (including archived)
        chat_list = driver.find_elements(By.XPATH, '//div[@data-testid="cell-frame-container"]')
        if not chat_list:
            continue

        for chat in chat_list:
            try:
                chat.click()
                time.sleep(2)

                if is_group_chat():
                    continue

                # Get all incoming and outgoing messages
                messages = driver.find_elements(By.XPATH, '//div[@role="row"]//div[@dir="ltr"]')
                if not messages:
                    continue

                from_you, msg = is_msg_from_you(messages)
                if not from_you or not msg.lower().startswith(GPT_TRIGGER):
                    continue

                if msg == last_handled:
                    continue

                print("Trigger found in your own chat:", msg)
                last_handled = msg
                prompt = msg[len(GPT_TRIGGER):].strip()

                # === OPENAI REQUEST ===
                completion = openai.ChatCompletion.create(
                    model="gpt-3.5-turbo",
                    messages=[
                        {"role": "system", "content": "You are a helpful AI assistant."},
                        {"role": "user", "content": prompt}
                    ]
                )
                reply = completion.choices[0].message.content.strip()
                print("GPT:", reply)

                # === SEND BACK ===
                input_box = driver.find_element(By.XPATH, '//div[@contenteditable="true"][@data-tab="10"]')
                input_box.click()
                input_box.send_keys(reply + Keys.ENTER)

            except Exception as chat_error:
                print("Chat scan error:", chat_error)
                continue

    except Exception as e:
        print("Main loop error:", e)
