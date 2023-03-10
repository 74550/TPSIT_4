import random

# utiliziamo questa classe come se fosse una struttura
class Node():
    def __init__(self, key):
        self.key = key
        self.left = None # discendente sinistro
        self.right = None # discendente destro

    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)

            elif key < self.key:
                if self.left is None:
                    self.left = Node(key)
                else:
                    self.left.insertNode(key)

        else:
            self.key = key

    def printTree(self, level = 0): # il livello sara inizializzato a 0
        if self.left is not None:
            self.left.printTree(level + 1)

        print(f"Livello: {level} -> {self.key}")

        if self.right is not None:
            self.right.printTree(level + 1)

    # algoritmo di ricerca di una key in un albero
    def findNode(self, key):
        if key > self.key:
            # andiamo a destra
            if self.right == None:
                return f"nodo {key} non trovato"
            return self.right.findNode(key)

        elif key < self.key:
            #andiamo a sinistra
            if self.left == None:
                return f"nodo {key} non trovato"
            return self.left.findNode(key)

        else:
            return f"nodo {key} trovato"
        
    def height(self):
        if self.left is None:
            heightL=0
        else:
            heightL=self.left.height()
        
        if self.right is None:
            heightR=0
        else:
            heightR=self.right.height()

        if heightL>heightR:
            return heightL+1
        else:
            return heightR+1

def BuildBTree(nodes):
        """
        nodes deve contenere valori ordinati crescenti
        """
        
        l = len(nodes)
        if l==0:
            return None
        nodes.sort()
        m=l//2
        print (f"nodo di mezzo: {m}-{nodes[m]}")
        root=Node(nodes[m])
        root.left=BuildBTree(nodes[0:m])
        root.right=BuildBTree(nodes[m+1:])
        return root
    
    


def main():
    listKey = list(range(0, 40, 5)) # da 0 a 40 saltanto di 5
    random.shuffle(listKey)
    print(listKey)
    listKey.sort()
    albero=BuildBTree(listKey)

    root = Node(listKey[1])

    for key in listKey[0:]:
        root.insertNode(key)

    root.printTree()
    print(root.findNode(20))
    print(f"l'altezza dell'albero è {albero.height()-1}")




if __name__ == "__main__":
    main()