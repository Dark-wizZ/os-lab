from tkinter import *

class LoanCalculator:
  def __init__(self):
    win = Tk()
    win.title('Loan Calc')
    #placing const labels
    for x, r, c in (
      ['Annual Interest Rate',1,1],
      ['Number of Years', 2, 1],
      ['Loan Amount', 3, 1],
      ['Monthly Payment', 4, 1],
      ['Total Payment', 5, 1]
    ):
      Label(win, text=x).grid(row=r,column=c, sticky=W)
    #placing input
    for x, r, c in (
      ['annIntRate',1,2],
      ['noYear',2,2],
      ['loanAmnt',3,2]
    ):
      setattr(self,x,StringVar())
      Entry(win, textvariable=getattr(self, x), justify=RIGHT).grid(row=r,column=c)
    #placing var lables
    for x, r, c in (
      ['monPay', 4, 2],
      ['totPay', 5, 2]
    ):
      setattr(self,x,StringVar())
      Label(win, textvariable=getattr(self,x), justify=RIGHT).grid(row=r,column=c,sticky=E)
      
    Button(win, text='Compute Payment', command=self.ComputePayment).grid(row=6, column=2)

    win.mainloop()
    
  def ComputePayment(self):
    intRate, year, loanAmt = [float(x) for x in [
      self.annIntRate.get(),
      self.noYear.get(),
      self.loanAmnt.get()
    ]]
    monInt = (intRate/100) / 12
    months = year * 12
    
    factor = (1+monInt)**months
    monPay = loanAmt * monInt * (factor/(factor-1))
    totPay = monPay * months
    self.totPay.set(f"{totPay:.2f}")
    self.monPay.set(f"{monPay:.2f}")

LoanCalculator()