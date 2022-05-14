import random

print("Hey welcome to ADI's cupcake shop!")
print("What is your name?")
user_name = input()
print("Hello, {0} ".format(user_name))

bot_template = "BOT : {0}"
user_template = user_name + " : {0}"

name = "Cupcakes shop Assistant"
flavours = "Mango, Chocolate, vanilla "
price = "Mango-50, Chocolate-70, Vanilla-60 (per piece)"
time = "10 AM to 9 PM"
bye = "Have a nice day!"

conversations = {
    "what's your name?": [
        "They call me {0}".format(name),
        "I usually go by {0}".format(name),
        "My name is the {0}".format(name),
    ],
    "what's today's available flavours?": [
        "The available flavours are {0}! Grab your favourite!".format(flavours),
        "It's {0} !!".format(flavours),
        "Let me check, the flavours available today are {0}!".format(flavours),
    ],
    "what are the timings of the shop?": [
        "The shop is opened from {0}! see you there! :)".format(time),
    ],
    "how are you?": [
        "I am fine! Hope you too!:)",
        "I am doing good!",
    ],
    "": [
        "Hey! Are you there?",
        "What do you mean by saying nothing?",
        "I didn't get your question :\") ",
        "Sometimes saying nothing tells a lot :)",
    ],
    "Good-bye": ["Have a nice day!", "See you again!"],
    "default": ["this is a default message"],
}


def respond(message):
    if message in conversations:
        bot_message = random.choice(conversations[message])
    else:
        bot_message = random.choice(conversations["default"])
    return bot_message


def related(x_text):
    if "name" in x_text:
        y_text = "what is your name?"
    elif "flavours" in x_text:
        y_text = "what's today's available flavours?"
    elif "price" in x_text:
        y_text = "What are the prices of the cakes?"
    elif "time" in x_text:
        y_text = "what are the timings of the shop?"
    elif "how are" in x_text:
        y_text = "how are you?"
    elif "bye" in x_text:
        y_text = "Good-bye"
    else:
        y_text = ""
    return y_text


def send_message(message):
    print(user_template.format(message))
    response = respond(message)
    print(bot_template.format(response))


while 1:
    my_input = input()
    my_input = my_input.lower()
    related_text = related(my_input)
    send_message(related_text)
    if my_input == "exit" or my_input == "stop":
        break
