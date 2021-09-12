class Node:
    def __init__(self, data):
        self.data = data
        self.next = None #None = null


class LinkedList:
    def __init__(self):
        self.curCount = 0 #현재 리스트 내에 있는 노드 개수
        self.headNode = Node("HeadNode")
    
    def showNode(self):
        print("현재 Node 개수 : "+str(self.curCount))
        tmpNode = self.headNode.next
        while(tmpNode != None):
            print("["+str(tmpNode.data)+"]")
            tmpNode = tmpNode.next
        print("-------------------------------")


    def addNode(self, pos, data):
        if (self.curCount < 0 or pos > self.curCount):
            print("In insertion : 추가 범위 초과")
            quit()
        
        newNode = Node(data)
        tmpNode = self.headNode

        for i in range(pos): #range의 값이 0 아래면 실행안됨
            tmpNode = tmpNode.next
        
        newNode.next = tmpNode.next
        tmpNode.next = newNode
        self.curCount += 1

    def deleteNode(self, pos):
        if(self.curCount < 0 or pos > self.curCount):
            print("In deletion : 추가 범위 초과")
            quit()
        #과제
        
    
    def isEmpty(self):
        #과제
    def findPos(self, data):
        #과제
    def makeEmpty(self):
        #과제
    


ll = LinkedList()
ll.addNode(0,1)
ll.addNode(0,2)
ll.showNode()
ll.deleteNode(1)
ll.showNode()