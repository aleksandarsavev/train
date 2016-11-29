"""
Entropy

When you can't learn in machine learning, you start to implement the theory.
It's much better to see the practical results then to learn a hundret million
pages of text.

Or...may be I'm just lazy and I don't want to learn.

author - Aleksandar Savev <savevjr@gmail.com>
"""
import json
import math
import datetime

def logger(msg):
    now = datetime.datetime.now()
    now_str = now.strftime("%Y-%m-%d %H:%M:%S")
    print("[" + now_str + "] " + str(msg))

def load_knowladge(filename, log=False):
    """
    Load knowlage database from json file

    filename - path to the json file
    """
    data = {"status" : "not loaded"}
    with open(filename, mode='r') as fil:
        data = json.load(fil)
    if not hasattr(data, "name"):
        data["name"] = filename
    if log:
        logger("Knowladge data loaded: '{0}'".format(data["name"]))
    return data

def norm(data, target):
    """
    Normalize the column name or index.

    data - data object
    target - target attribute name or index
    returns - if target is string - return the index of this string in the list of attribute names
    """
    if isinstance(target, str):
        return data["attributes"].index(target)
    return target

def entropy(data, target, log=False):
    """
    Calculate the entropy of the given target atrtibute.

    data - data object
    target - target attribute name or index
    """
    return entropy_list(data["rows"], norm(data, target), log)

def entropy_list(rows, target, log=False):
    """
    Calculate the entropy of the given target atrtibute.

    rows - list of lists, containing the data
    target - index of the column
    """
    values_count = {}
    for entry in rows:
        value = entry[target]
        if value in values_count:
            values_count[value] += 1
        else:
            values_count[value] = 1
    ent = 0
    for _, count in values_count.items():
        prop = count / len(rows)
        val = prop * math.log2(prop)
        if log:
            logger("Bits needed [" + _ + "]" + ": " + str(val))
        ent += val
    return -ent

def entropy_cond(data, target, cond, log=False):
    count_before = len(data["rows"])
    filtered = [x for x in data["rows"] if x[norm(data, cond[0])] == cond[1]]
    count_after = len(filtered)
    if log:
        logger("Condition -> attribute[{}] == {}".format(cond[0], cond[1]))
        logger("Filtered items: {}.".format(count_before - count_after))
    return entropy_list(filtered, norm(data, target), log)

def information_gain_list(rows, target, test, log=False):
    entropy_parent = entropy_list(rows, target, log)
    distinct_test = distinct_values(rows, test, log)



def distinct_values(rows, target, log=False):
    for row in 
    result = set([row[target] for row in rows])
    return result


DATA = load_knowladge("know_002.json")
logger(entropy(DATA, "X", log=True))
logger(entropy(DATA, "Y", log=True))
logger(entropy_cond(DATA, "Y", ("X", "Math"), log=True))
logger(entropy_cond(DATA, "Y", ("X", "History"), log=True))

#print(-sum(entropy_cond(DATA, 3, (0, "red"))))
