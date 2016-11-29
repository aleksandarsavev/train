import json

MATRIX = "matrix"
WATER_C = "W"
NOTHING_C = "O"

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
    def __init__(self, o: dict):
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
                ch = WATER_C
                if c is None:
                    ch = NOTHING_C
                elif type(c) is Island:
                    ch = c.count
                print(f.format(ch), end='')
            print('')

    def it(self):
        """ Iterates all cells
            Returns tuples in format ([y], [x], [object])
        """
        for i in range(0, self.height):
            for j in range(0, self.width):
                yield (i, j, self.m[i][j])

    def isolate(self):
        """ Isolate islands which are fully uncoverd. """
        for c in self.it():
            if type(c[2]) is Island:
                island = c[2]
                if island.count == len(island.found) and not island.isolated:
                    for cell in island.found: self.isolate_cell(cell)
                    island.isolated = True

    def isolate_cell(self, cell):
        """ Surround cell with Water

            cell   : tuple with coordinates of the cell
            island : Island where the cell belongs to
        """
        self.cover_water(cell[0] + 1, cell[1])
        self.cover_water(cell[0] - 1, cell[1])
        self.cover_water(cell[0], cell[1] + 1)
        self.cover_water(cell[0], cell[1] - 1)

    def split_neigh(self):
        for i in range(0, self.height):
            for j in range(0, self.width):
                if i < self.height - 2:
                    self.split_neigh_d(i, j, 2, 0)
                
                if i >= 2:
                    self.split_neigh_d(i, j, -2, 0)
                
                if j < self.width - 2:
                   self.split_neigh_d(i, j, 0, 2)
                
                if j >= 2:
                    self.split_neigh_d(i, j, 0, -2)
    
    def split_neigh_d(self, i, j, di, dj):
        ii = di // 2
        jj = dj // 2
        a, b, c = self.m[i][j], self.m[i + ii][j + jj], self.m[i + di][j + dj]
        if a is not c and type(a) is Island and type(b) is not Island and type(c) is Island:
            self.cover_water(i + ii, j + jj)

    def cover_water(self, y, x):
        """ Cover cell with water only if the cell is empty. Otherwise the method does nothing. """
        if y >= 0 and y < self.height and x >= 0 and x < self.width:
            if self.m[y][x] is None:
                self.m[y][x] = self.WOTAH

    def separate_islands(self):
        for c in self.it():
            pass

    def check_nb(self, c1, c2):
        pass


def read_matrix(filename: str):
    f = open(filename, 'r')
    m = Matrix(json.load(f))
    f.close()
    return m

mm = read_matrix("nurikabe_001.json")

mm.print()
print('')
mm.isolate()
print('')
mm.print()
mm.split_neigh()
print('')
mm.print()
