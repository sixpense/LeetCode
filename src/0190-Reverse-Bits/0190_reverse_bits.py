class Solution:
    def reverseBits(self, n: int) -> int:
        print('Int-->',n)
        bin_n = bin(n)[2:].rjust(32,'0')
        print('Binary -->',bin_n)

        int_n = bin_n[::-1]
        print('Reversed Int -->',int_n)
        num = int(int_n,2)

        return num
