# Created 13-09-2016
# Author Aleksandar <savevjr@gmail.com>

from random import randint

def gen(chars, length):
    return ''.join([chars[randint(0, len(chars)) - 1] for i in range(0, length)])

def collide(chars, length):
    first = gen(chars,length)
    counter = 0
    while(first != gen(chars, length)):
        counter += 1
    return counter

def collide_test(chars, length):
    print(str(length) + ": " + str(collide(chars, length)))

lower_en = "abcdefghijklmnopqrstuvwxyz"
upper_en = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
all_en = lower_en + upper_en
