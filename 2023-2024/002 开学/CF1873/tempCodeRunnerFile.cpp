 // if(t==1000){

    //     while(t--){
    //     memset(h,-1,sizeof h);
    //     idx=0;xx=0,yy=0;
    //     r.clear();
    //     read(n),read(a),read(b);
    //     cout<<n<<" "<<a<<" "<<b<<endl;
    //     for(int i=1;i<=n;i++){
    //         vis[i]=0;
    //         int x,y;
    //         read(x),read(y);
    //         if(t==975) cout<<x<<" "<<y<<endl;
    //     }

    //     // if(a==b){cout<<"NO"<<endl;continue;}

    //     dfs1(0,1);

    //     int op=rs;
    //     while(vis[op]!=0){
    //         vis[op]=0;
    //         r.push_back(op);
    //         op=fr[op];
    //     }

    //     // for(auto i:r) cout<<i<<endl;

    //     int l1=dfs2(0,b,0);

    //     int l2=dfs4(0,a,0);

    //     int op1=find(r.begin(),r.end(),xx)-r.begin(),op2=find(r.begin(),r.end(),yy)-r.begin();

    //     int u=abs(op1-op2),siz=r.size();

    //     l2+=min(u,siz-u);
    // }