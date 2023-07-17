import random

# Define a list of words
lista = ["apple", "banana", "carrot", "dog", "elephant", "frog", "giraffe", "honey", "igloo", "jaguar"]
c = 0
word_list = []
for i in lista:
    i = i.upper()
    word_list.append(i)
    c += 1
# Generate the image of a "body"
def get_body(body, chance):
    if chance < 6:
        print(body[0])
    if chance == 4:
        print(body[1])
    elif chance == 3:
        print(body[2])
    elif chance <= 2:
        print(body[3])
    if chance == 1:
        print(body[4])
    elif chance < 1:
        print(body[5])
        print("\n YOU KILL THIS MAN")
        return

def print_quest(question):
    for i in question:
        print(i, end=" ")
    return

def get_answer(answer, trys, question):
    situation = True
    for i in range(len(kick_answer)):
        if kick_answer[i] == trys.upper():
            question[i] = trys.upper()
            situation = False
    return situation
    
def game(answer: str, 
    kick_answer = [], question = []):
    question = ["_" for i in answer]
    chance = 6
    while(chance > -1):
        error = True
        body = [" O"," |", "/| ", "/|\\","/", "/\\"]
        get_body(body, chance)
        if chance == 0:
            break
        print_quest(question)
        trys = input("\nWich word is? ")
        if answer == trys.upper():
            print("You\'re right, the answer is {}".format(answer))
            break
        error = get_answer(answer, trys, question)
        coisa = ''.join(question)
        if coisa.upper() == answer:
            print("You\'re right, the answer is {}".format(answer))
            break
        if error:
            chance -= 1
if __name__ == '__main__':
    a = random.randint(1, c-1)
    answer = word_list[a]
    kick_answer = [i for i in answer]
    game(answer, kick_answer, [])
    while(True):
        gamer =input("Você quer jogar de novo?")
        if gamer == "s":
            
            a = random.randint(1, c-1)
            answer = word_list[a]
            kick_answer = [i for i in answer]
            game(answer, kick_answer, [])
        else:
            break
