import json

MATRIX = "matrix"

class Island(object):
    def __init__(self, count, first):
        self.count = count
        self.found = [first]
        self.isolated = False
    
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
        self.WOTAH = Water()

        for i in range(0, self.height):
            for j in range(0, self.width):
                c = o[MATRIX][i][j]
                self.m[i][j] = Island(c, (i, j)) if c > 0 else None

    def __str__(self):
        return str(self.o[MATRIX])

    def print(self):
        for i in range(0, self.height):
            for j in range(0, self.width):
                c = self.m[i][j]
                f = "{:>4}"
                ch = 'W'
                if c is None:
                    ch = 'N'
                elif type(c) is Island:
                    ch = c.count
                print(f.format(ch), end='')
            print('')

    def it(self):
        for i in range(0, self.height):
            for j in range(0, self.width):
                yield (i, j, self.m[i][j])

    def isolate(self, island=None):
        if island is None: 
            for c in self.it():
                if type(c[2]) is Island:
                    if c[2].count == len(c[2].found) and not c[2].isolated:
                        self.isolate(c[2])
        else:
            for c in island.found:
                self.isolate_c(c)
            island.isolated = True

    def isolate_c(self, cell):
        """ Surround cell with Water

            cell   : tuple with coordinates of the cell
            island : Island where the cell belongs to
        """
        self.cover_water((cell[0] + 1, cell[1]))
        self.cover_water((cell[0] - 1, cell[1]))
        self.cover_water((cell[0], cell[1] + 1))
        self.cover_water((cell[0], cell[1] - 1))

    def cover_water(self, cell):
        """ Cover cell with water """
        if cell[0] >= 0 and cell[0] < self.width and cell[1] >= 0 and cell[1] < self.height:
            if self.m[cell[0]][cell[1]] is None:
                self.m[cell[0]][cell[1]] = self.WOTAH

    def separate_islands(self):
        for c in self.it():
            pass

    def check_nb(self, c1, c2):
        pass


def read_matrix(filename):
    f = open(filename, 'r')
    m = Matrix(json.load(f))
    f.close()
    return m

mm = read_matrix("nurikabe_001.json")

mm.print()
print('')
mm.isolate()
mm.print()
