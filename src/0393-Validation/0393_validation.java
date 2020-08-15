class Solution {
public:
    public boolean validUtf8(int[] data) {
        int i = 0;
        while(i < data.length) {
            // 0x80: 10000000
            // 0x40: 01000000
            int mark = 0x80, count = 0;

            // 获取对应位置的字节数, 注意字节数位置为1时, count为0.
            while((mark & data[i]) != 0) {
                mark >>= 1;
                count ++;
            }
            i++;
            int k = i + count - 1;

            if(count == 1 || count > 4 || k > data.length )
                return false;
            while(i < k) {
                if((data[i] & 0x80) == 0 || (data[i] & 0x40) != 0) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
}
