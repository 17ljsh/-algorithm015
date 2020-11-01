class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        int start = 0;
        while (length > 0) {
            //����2k�ʹ���k���Ժϲ�����
            if (length >= k ) {
                //��ת��㿪ʼ��k���ַ�
                reverse(s.begin() + start, s.begin() + start + k);
                //���³��Ⱥ����
                length -= 2*k;
                start += 2*k;
            }
            else if (length < k) {
                //��תʣ�µ�
                reverse(s.begin() + start,s.end());
                length = 0;
            }
        }
        return s;
    }
};