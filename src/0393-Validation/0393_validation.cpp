/*
 * A character in UTF-8 can be from 1 to 4 bytes long, subjected to the following rules:
 * 1. For 1-bytes character, the first bit is a 0, followed by its unicode code.
 * 2. For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by
 * n-1 bytes with most signifiacnt 2 bits being 10.
 *
 * This is how the UTF-8 encoding would work:
 * Char. number range      |            UTF-8 octet sequence
 *   (hexadecimal)         |                   (binary)
 * ------------------------+-------------------------------------------
 * 0000 0000-0000 007F     |  0*******
 * 0000 0080-0000 07FF     |  110***** 10********
 * 0000 0800-0000 FFFF     |  1110**** 10******** 10********
 * 0001 0000-0010 FFFF     |  11110*** 10******** 10******** 10********
 *
 * Given an array of integers representing the data, return whether it is a valid UTF-8
 * encoding.
 *
 * Note:
 * The input is an array of integers. Only the least significant 8 bits of each integer is
 * used to store the data. This means each integer represents only 1 byte of data.
 *
 * Example 1:
 * data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
 * Return true.
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
 * Example 2:
 * data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
 * Return false.
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
 * The next byte is a continuation byte which starts with 10 and that's correct.
 * But the second continuation byte does not start with 10, so it is invalid.
 */

// 1) 判断第一位, 如果是0, 说明是ASCII码, 直接跳过
// 2) 如果该数大于等于128, 则表示第一位是1, 然后减去128, 如果得到的数大于等于64, 表示第二位
// 是1, 依次类推.
// 3) 连续的个数不能超过4, 当cnt > n - i 时, 返回为false.
// 4) 验证后面的字节是否是10开头, 判断这个数在10000000~10111111范围之内.

class Solution {
public:
    boo validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i = 0; i < n; ++i) {
            if(data[i] < 0b10000000) {
                continue;
            }
            else {
                int cnt = 0, val = data[i];
                for(int j = 7; j >= 1; --j) {
                    if(val >= pow(2, j))
                        ++cnt;
                    else
                        break;
                    val -= pow(2, j);
                }
                if(cnt == 1 || cnt > 4 || cnt > n - i)
                    return false;
                for(int j = i + 1; j < i + cnt; ++j) {
                    if(data[j] > 0b10111111 || data[j] < 0b10000000)
                        return false;
                }
                i += cnt - 1;
            }
        }
        return true;
    }
};
