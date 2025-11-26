bool isPalindrome(int x) {
    long int temp=x;
    int r,base=1;
    long int res=0;
    
    while(temp!=0){
        r=temp%10;
        res=(res*base)+r;
        base=10;
        temp/=10;
        
    }
    if(x==res && x>=0){
        return true;
    }else{
        return false;
    }
    
}