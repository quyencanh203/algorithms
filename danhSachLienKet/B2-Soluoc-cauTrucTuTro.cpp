/*
===================CẤU TRÚC TỰ TRỎ ===================
       struct node{
        int data;
        struct node *next; // link
       };

              giải thích ý nghĩa của cấu trúc node
       * Node ở đây có phần dữ liệu là một số nguyên lưu ở data, ngoài ra còn có 1
         phần con trỏ tới chính strucst node. Phần này chính là địa chỉ của node 
         tiếp theo của nó trong dslk.
       * như vậy mỗi node sẽ có địa chỉ của nó và địa chỉ của node tiếp sau nó. Đối 
         với con trỏ cuối cùng trong dslk thì phần địa chỉ này sẻ là con trỏ NULL.

*/