import json

class Island(object):
    def __init__(self, count):
        self.count = count
    
    def __str__(self):
        return str(self.count)

class Water(object):
    pass

class Matrix(object):
    def __init__(self, o):
        self.width = o["width"]
        self.height = o["height"]
        self.m = [[None for j in range(0, self.width)] for i in range(0, self.height)]
        self.o = o
        
        wotah = Water()

        for i in range(0, self.height):
            for j in range(0, self.width):
                c = o["matrix"][i][j]
                self.m[i][j] = Island(c) if c > 0 else wotah

    def __str__(self):
        return str(self.o["matrix"])

def read_matrix(filename):
    f = open(filename, 'r')
    m = Matrix(json.load(f))
    f.close()
    return m

mm = read_matrix("nurikabe_001.json")
print(mm)
