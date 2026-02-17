class car:
    def __init__(self, name,color) :
        print(f"Object at {self} is deployed")
        self.name=name
        self.color=color
        self.state=False

    def start(self):
        self.state=True
        print("Behavior modified")

car1=car("Honda","Red")
car1.start()
    