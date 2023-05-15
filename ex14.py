from tkinter import *

class PopupMenu():
  def __init__(self):
    win = Tk()
    win.title('PopUp Menu')
    for x, v in (
      ('Number 1:','v1'),
      ('Number 2:','v2'),
      ('Result:', 'v3')
    ):
      setattr(self,v,StringVar())
      Label(win, text=x).pack(side=LEFT)
      Entry(win, textvariable=getattr(self,v), justify=RIGHT).pack(side=LEFT)
      
    self.canvas = Canvas(win, height=100, width=200)
    self.canvas.pack()
    self.canvas.bind("<Button>", self.popup)
    
    self.menu = Menu(win, tearoff=0)
    for x in ['add', 'subtract', 'multiply', 'divide']:
      self.menu.add_command(label = x, command=getattr(self,x))
    
    win.mainloop()
  def popup(self, e):
    self.menu.post(e.x_root, e.y_root)
  def add(self):
    self.v3.set(int(self.v1.get())+int(self.v2.get()))
  def subtract(self):
    self.v3.set(int(self.v1.get())-int(self.v2.get()))
  def multiply(self):
    self.v3.set(int(self.v1.get())*int(self.v2.get()))
  def divide(self):
    self.v3.set(int(self.v1.get())/int(self.v2.get()))
PopupMenu()