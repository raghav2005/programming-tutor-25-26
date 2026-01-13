class Z:
    def __init__(self, _float):
        self._float = _float

class A:

    val = 'hi'
    
    def __init__(self, _num, _string):
        self._num = _num
        self._string = _string

    def setNum(self, _num):
        self._num = _num

a = A(1, '2')
b = A(2, '3')

a.setNum(4)

print(a._num, b._num)
print(a.val, b.val)
