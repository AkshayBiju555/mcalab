class Publisher:
    def __init__(this,name):
        this.name=name
    def display(this):
        print(f"publisher is {this.name}")
class Book(Publisher):
    def __init__(this,name,title,author):
        super().__init__(name)
        this.title=title
        this.author=author
    #method overriding
    def display(this):
        print(f"Tile:{this.title}\nAuthor:{this.author}")
    
class Python(Book):
    def __init__(this,name,title,author,price,numofpages):
        super().__init__(name,title,author)
        this.price=price
        this.numofpages=numofpages
    # again method overriding
    def display(this):
        print(f"price:${this.price}\nnumber of pages:{this.numofpages}")

book=Python(name="DC Books",title="deception point",author="Dan Brown",price=24.99,numofpages=300)
#book.display() #overrides the other two display methods
#Book.display(book) #to call display() in book class
#Publisher.display(book)  #to call display() in publisher class
