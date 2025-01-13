 i=0;i<=30;i++) op[i]=-1;
        // for(int i=m-1;i>=0;i--){
        //     int k=str[i]-'a';
        //     if(str[i]>='a'&&str[i]<='z') op[k]=i;
        //     for(int j=0;j<26;j++) nxt[i][j]=op[j];
        // }
        // for(int i=1;i<=n;i++){
        //     int pos=0;
        //     for(int j=0;j<name[i].length();j++){
        //         int k=name[i][j]-'a';
        //         if(j==0){
        //             if(name[i][0]==str[0]) pos=0;
        //             else pos=nxt[0][k];
        //             continue;
        //         }
        //         if(pos==-1) break;
        //         pos=nxt[pos+1][k];
        //     }
        //     if(pos!=-1) ans+=sum[pos];
        //     // cout<<pos<<endl;
        // }