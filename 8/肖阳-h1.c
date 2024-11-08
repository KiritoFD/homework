char* bestHand(int* ranks, int ranksSize, char* suits, int suitsSize) {
    bool flush=true;
    for(int i=0;i<ranksSize-1;i++){
        if(suits[i]!=suits[i-1]) flush=false;
    }if(flush) return "Flush";
    int count[15]={0};
    for(int i=0;i<ranksSize;i++){
        count[ranks[i]]++;
    }
    for(int i=0;i<15;i++){
        if(count[i]>=3) return "Three of a Kind";
    }
    for(int i=0;i<15;i++){
        if(count[i]==2) return "Pair";
    }
    return "High Card";
}