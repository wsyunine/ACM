//添加记录：通过用户输入日期、金额、备注等信息，创建新的 msg 对象，并添加到 msg_collection 中。
//删除记录：通过记录编号，删除指定记录。
//修改记录：通过记录编号，修改指定记录的内容。
//查询和统计：根据用户输入的时间段，查询并统计相应的记录。
//文件操作：实现记录的二进制文件存储和读取功能。

#include<iostream>
#include<iomanip>
#include<ctime>
#include"msg.h"
#include"logger.h"
#include<string>
#include<vector>
#include<fstream>
#include<stdexcept>
using namespace std;

//后面判断日期是否合法有用
const int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

//创建一个记录集对象
msg_collection msgc;

//初始界面
int init_print_msgs(){
    //记录共显示了多少条记录
    int sum=0;
    //按时间由近及远排列
    msgc.sort_msg(date_oriented_down);
    //表头
    cout<<setw(8)<<"ID"<<setw(15)<<"Date"<<setw(15)<<"State"<<setw(15)<<"Amount"<<setw(15)<<"Text"<<endl;
    //挨个取，直到取完或取了10个
    for(int i=0;i<msgc.get_size();i++){
        //取了10个了，退出
        if(sum==10) break;
        //当前这个记录已经被删除了，或不合法，跳过
        if(msgc[i].get_amount()==0) continue;
        //显示
        sum++;
        msgc.print_msg(i);
    }
    //返回显示了多少记录
    return sum;
}

//选择界面
int enter_choice(){

    cout<<endl;
    //分隔线，清晰
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout<<"You can do the following operations:"<<endl;
    //添加
    cout<<"1 Add a accounting record"<<endl;
    //删除
    cout<<"2 Delete a accounting record"<<endl;
    //修改
    cout<<"3 Modify a accounting record"<<endl;
    //查询三个数值：总收入、总支出、净结余
    cout<<"4 Query the total income/total expenditure/net balance in a certain period of time"<<endl;
    //查询明细：按一定顺序输出
    cout<<"5 Query the income/expenditure details in a certain period of time"<<endl;
    //退出程序
    cout<<"6 End program"<<endl;
    cout<<endl<<"Please enter the number corresponding to the operation: ";
    int opt;
    cin>>opt;
    return opt;

}

//添加一条记账记录
void choice_1(){
    string sop,textt;
    date t;
    double aop;
    //支出or收入
    cout<<"Add a new expenditure/income record: ";
    cin>>sop;
    //错误输入判断
    if(sop!="expenditure"&&sop!="income"){
        Logger::log("添加失败");
        cout<<"Error!"<<endl;
        return;
    }
    //输入日期
    cout<<"Please enter the date of "<<sop<<" in the format of YYYY/MM/DD: ";
    cin>>t;
    //错误输入判断
    if(!t.is_right()){
        Logger::log("添加失败");
        cout<<"Error!"<<endl;
        return;
    }
    //输入金额
    cout<<"Please enter the amount of "<<sop<<": ";
    cin>>aop;
    //金额不能小于等于0
    if(aop<=0){
        Logger::log("添加失败");
        cout<<"Error!"<<endl;
        return;
    }
    //备注
    cout<<"Notes: ";
    //跳过一个换行符
    cin.ignore();
    //可以读取一行文字
    getline(cin,textt);
    //使用构造函数生成一个msg对象
    //调用add_msg成员函数
    msgc.add_msg(msg(0,t,(sop=="expenditure")?1:0,aop,textt));
    //成功提示
    cout<<"Adding a accounting record succeeded!"<<endl;
}

//删除一个记账记录
void choice_2(){
    int del_id;
    //通过编号删除
    cout<<"Please enter the number of the accounting record you want to delete: ";
    cin>>del_id;
    //如果输入的超过了动态数组的大小，访问会报错
    if(del_id>msgc.get_full_size()){
        Logger::log("删除失败");
        cout<<"Error!"<<endl;
        return;
    }
    //如果删除失败就退出
    if(msgc.del_msg(del_id)==0){
        cout<<"Error!"<<endl;
        return;
    }
    //成功提示
    cout<<"Deleting a accounting record succeeded!"<<endl;
}

//修改一个记账记录
void choice_3(){
    string sop,textt;
    date t;
    double aop;
    int mod_id;
    cout<<"Please enter the number of the accounting record you want to modify: ";
    cin>>mod_id;
    //错误输入判断
    if(mod_id>msgc.get_full_size()){
        Logger::log("修改失败");
        cout<<"Error!"<<endl;
        return;
    }
    cout<<"Modify it into a expenditure/income record: ";
    cin>>sop;
    //错误输入判断
    if(sop!="expenditure"&&sop!="income"){
        Logger::log("修改失败");
        cout<<"Error!"<<endl;
        return;
    }
    cout<<"Please enter the date of "<<sop<<" in the format of YYYY/MM/DD: ";
    cin>>t;
    //错误输入判断
    if(!t.is_right()){
        Logger::log("修改失败");
        cout<<"Error!"<<endl;
        return;
    }
    cout<<"Please enter the amount of "<<sop<<": ";
    cin>>aop;
    //金额不能小于等于0
    if(aop<=0){
        Logger::log("修改失败");
        cout<<"Error!"<<endl;
        return;
    }
    //输入备注
    cout<<"Notes: ";
    //跳过一个换行符
    cin.ignore();
    //读取一行文字
    getline(cin,textt);
    //使用构造函数生成一个msg对象
    //调用mod_msg成员函数
    //如果修改失败就退出
    if(msgc.mod_msg(mod_id,msg(0,t,(sop=="expenditure")?1:0,aop,textt))==0){
        cout<<"Error!"<<endl;
        return;
    }
    //成功提示
    cout<<"Modifying a accounting record succeeded!"<<endl;
}

void choice_4(){
    date t1,t2;
    cout<<"Please enter a start time in the format of YYYY/MM/DD: ";
    cin>>t1;
    //错误输入判断
    if(!t1.is_right()){
        Logger::log("查询失败");
        cout<<"Error!"<<endl;
        return;
    }
    cout<<"Please enter a end time in the format of YYYY/MM/DD: ";
    cin>>t2;
    //错误输入判断
    if(!t2.is_right()){
        Logger::log("查询失败");
        cout<<"Error!"<<endl;
        return;
    }
    //如果反了，就反过来
    if(t2<t1){
        date op=t1;
        t1=t2;
        t2=op;
    }
    //计算
    msgc.calc_msgs(t1,t2);
}

void choice_5(){
    date t1,t2;
    int num;
    cout<<"Please enter a start time in the format of YYYY/MM/DD: ";
    cin>>t1;
    //错误输入判断
    if(!t1.is_right()){
        Logger::log("查询失败");
        cout<<"Error!"<<endl;
        return;
    }
    cout<<"Please enter a end time in the format of YYYY/MM/DD: ";
    cin>>t2;
    //错误输入判断
    if(!t2.is_right()){
        Logger::log("查询失败");
        cout<<"Error!"<<endl;
        return;
    }
    //如果反了，就反过来
    if(t2<t1){
        date op=t1;
        t1=t2;
        t2=op;
    }
    cout<<"How do you want the accounting records to be arranged?"<<endl;
    //按编号顺序排列
    cout<<"1 Arrange by id number"<<endl;
    //按日期顺序排列
    cout<<"2 Arrange in date order"<<endl;
    //按日期倒序排列
    cout<<"3 Arrange in reverse order of date"<<endl;
    //按金额降序排列
    cout<<"4 Arrange in descending order of amount"<<endl;
    //按金额升序排列
    cout<<"5 Arrange in ascending order of amount"<<endl;
    cout<<"Please enter the number: ";
    cin>>num;
    //错误输入判断
    if(num<=0||num>5){
        Logger::log("查询失败");
        cout<<"Error!"<<endl;
        return;
    }
    //计算
    msgc.print_msgs(t1,t2,num);

}

int main(){

    Logger::log("程序启动");
    //以二进制形式打开data.txt文件，读取其中数据
    fstream ifile("data.txt",ios::out|ios::in|ios::binary);
    //如果找不到文件就报错
    if(!ifile){
        cerr<<"File could not be opened."<<endl;
        Logger::log("数据文件打开失败，退出程序");
        exit(EXIT_FAILURE);
    }
    //读取记录
    msgc.read_all_msg(ifile);
    //关闭文件
    ifile.close();
    Logger::log("数据读取完成");


    //界面
    cout<<"Recent accounting records: "<<endl;
    int op=init_print_msgs();
    //展示了 条，共有 条
    cout<<"Showed "<<op<<" accounting records, a total of "<<msgc.get_size()<<" accounting records."<<endl;
    Logger::log("显示菜单");
    int tmp=enter_choice();
    //重复询问，直到退出
    while(tmp!=6){
        //错误输入判断
        if(tmp>6||tmp<=0){
            Logger::log("未知命令："+to_string(tmp));
            cout<<"The number entered is illegal, please re-enter: ";
            cin>>tmp;
            continue;
        }

        switch(tmp){
            case 1: 
                //添加
                Logger::log("执行命令: 添加记录");
                choice_1();
                break;
            case 2: 
                //删除
                Logger::log("执行命令: 删除记录");
                choice_2();
                break;
            case 3: 
                //修改
                Logger::log("执行命令: 修改记录");
                choice_3();
                break;
            case 4: 
                //查询三个金额
                Logger::log("执行命令: 查询金额");
                choice_4();
                break;
            case 5: 
                //查询明细并以一定的顺序输出
                Logger::log("执行命令: 查询明细");
                choice_5();
                break;
        }

        //询问操作
        Logger::log("显示菜单");
        tmp=enter_choice();
    }


    cout<<"-----------------------------------------------------------------------------------"<<endl;
    //以二进制形式打开文件，清除内容，重新填写
    fstream ofile("data.txt",ios::trunc|ios::out|ios::binary);
    //找不到就报错
    if(!ofile){
        cerr<<"File could not be opened."<<endl;
        Logger::log("数据文件打开失败，退出程序");
        exit(EXIT_FAILURE);
    }
    // for(int i=1;i<=20;i++){
    //     msg x(i,date(2024,2,(i+rand())%20),rand()%2,(double)rand()/(double)rand(),"what");
    //     ofile.write(reinterpret_cast<const char*>(&x),sizeof(msg));
    // }

    //写入记录
    msgc.write_all_msg(ofile);
    //关闭文件
    ofile.close();
    Logger::log("数据文件写入完成");

    Logger::log("程序结束");
    return 0;
}

//-------------------------------------------------------------------------------

string date::tostring()const{
    string res="";
    res=to_string(yr)+"/"+to_string(mth)+"/"+to_string(dy);
    return res;
}

//判断是不是闰年
bool date::is_run()const{
    if((yr%4==0)&&(yr%100!=0)) return 1;
    if(yr%400==0) return 1;
    return 0;
}

//判断日期是否合法
bool date::is_right()const{
    //获取当前系统时间
    time_t now = time(nullptr);
    //使用当前时间创建结构体
    tm* currentTime = localtime(&now);
    //获取年、月、日
    int year = 1900 + currentTime->tm_year;
    int month = 1 + currentTime->tm_mon;
    int day = currentTime->tm_mday;
    //判断是否超出范围以及超出今年
    if(yr<1970||yr>year) return 0;
    //判断是否超出范围以及超出这个月
    if(mth<=0||mth>12||(yr==year&&mth>month)) return 0;
    //判断是否超出范围以及超出今天
    if((yr==year&&month==mth)&&(dy<=0||dy>day)) return 0;
    //判断日期存不存在
    if(dy<=0||dy>days[mth]) return 0;
    if(!is_run()&&mth==2&&dy>28) return 0;
    //存在
    return 1;
}

//设置年
void date::set_year(int yr){this->yr=yr;}

//设置月
void date::set_month(int mth){this->mth=mth;}

//设置日
void date::set_day(int dy){this->dy=dy;}

//设置日期
void date::set_date(int yr,int mth,int dy){
    set_year(yr);
    set_month(mth);
    set_day(dy);
}

//打印日期
void date::print_date(ostream &output)const{
    output<<yr<<"/"<<mth<<"/"<<dy<<endl;
}

//读取日期
date date::read_date(istream &input){
    input>>yr;
    //忽略/
    input.ignore();
    input>>mth;
    //忽略/
    input.ignore();
    input>>dy;
    //this指针指向该对象
    return *this;
}

//重载比较符号用来比较日期前后
bool date::operator<(const date& x){
    if(yr==x.yr&&mth==x.mth){
        return dy<x.dy;
    }else if(yr==x.yr){
        return mth<x.mth;
    }else{
        return yr<x.yr;
    }
}

bool date::operator>(const date& x){
    if(yr==x.yr&&mth==x.mth){
        return dy>x.dy;
    }else if(yr==x.yr){
        return mth>x.mth;
    }else{
        return yr>x.yr;
    }
}

//重载流插入流输出符号，实现输入输出日期
ostream &operator<<(ostream &output,const date &x){
    string res=to_string(x.yr)+'/'+to_string(x.mth)+'/'+to_string(x.dy);
    output<<res;
    //为了实现连续输出
    return output;
}

istream &operator>>(istream &input,date &x){
    input>>x.yr;
    //忽略/
    input.ignore();
    input>>x.mth;
    //忽略/
    input.ignore();
    input>>x.dy;
    //为了实现连续读入
    return input;
}

//-------------------------------------------------------------------------------

//列表化初始化构造函数
msg::msg(int id,date t,bool is_payout,double amount,string text):
id(id),t(t),is_payout(is_payout),amount(amount) {
    set_text(text);
}

//取编号
int msg::get_id()const{return id;}

//取金额
double msg::get_amount()const{return amount;}

//设置金额
void msg::set_amount(double x){amount=x;}

//设置编号
void msg::set_id(int x){id=x;}

//设置备注
void msg::set_text(string x){text=x;}

//取备注
string msg::get_text()const{return text;}

//取日期
date msg::get_date()const{return t;}

//取收入支出状态
bool msg::get_ie()const{return is_payout;}

//显示记录
void msg::show_msg()const{
    //流操纵符 左对齐
    cout<<left<<setw(15)<<id;
    cout<<left<<setw(15)<<t;
    cout<<left<<setw(15)<<(is_payout?"Expenditure":"Income");
    cout<<setw(15)<<amount;
    cout<<setw(15)<<text<<endl;
}

//输出记录
void msg::print_msg(ostream &output)const{
    //流操纵符 左对齐
    output<<left<<setw(15)<<id;
    output<<setw(15)<<t;
    output<<left<<setw(15)<<(is_payout?"Expenditure":"Income");
    output<<setw(15)<<amount;
    output<<setw(15)<<text<<endl;
}

//重载流输出运算符，实现输入输出记录
ostream &operator<<(ostream &output,const msg &x){
    //流操纵符 左对齐
    output<<left<<setw(15)<<x.id;
    output<<setw(15)<<x.t;
    output<<left<<setw(15)<<(x.is_payout?"Expenditure":"Income");
    output<<setw(15)<<x.amount;
    output<<setw(15)<<x.text<<endl;
    //为了实现连续输出
    return output;
}

//排序用函数
//按编号顺序
bool id_oriented(msg a,msg b){
    return a.id<b.id;
}

//按日期顺序
bool date_oriented_up(msg a,msg b){
    return (!(a.t>b.t)&&!(a.t<b.t))?a.id<b.id:a.t<b.t;
}

//按日期倒序
bool date_oriented_down(msg a,msg b){
    return (!(a.t>b.t)&&!(a.t<b.t))?a.id<b.id:a.t>b.t;
}

//按金额降序
bool amount_oriented_up(msg a,msg b){
    return a.amount==b.amount?a.id<b.id:a.amount<b.amount;
}

//按金额升序
bool amount_oriented_down(msg a,msg b){
    return a.amount==b.amount?a.id<b.id:a.amount>b.amount;
}

//-------------------------------------------------------------------------------

//构造函数
msg_collection::msg_collection(int siz):siz(siz){}

//取记录集中有效记录的个数
int msg_collection::get_size()const{
    int sum=0;
    //金额不为0的记录为有效记录
    for(msg x:s) if(x.get_amount()) sum++;
    return sum;
}

//取数组大小
int msg_collection::get_full_size()const{return siz;}

//读入所有记录
void msg_collection::read_all_msg(fstream &ofile){
    msg x;
    //强制类型转换为char*类型，用流的read函数读取记录
    ofile.read(reinterpret_cast<char*>(&x),sizeof(msg));
    //一直读到结尾
    while(!ofile.eof()){
        //读到一个msg对象
        siz++;
        //如果有编号就直接加进记录集里
        if(x.get_id()!=0){
            s.push_back(x);
        }else{
            //没有编号就给它一个编号
            s.push_back(msg(siz));
        }
        //再读
        ofile.read(reinterpret_cast<char*>(&x),sizeof(msg));
    }
}

//按一定顺序排序
//传入一个函数指针
void msg_collection::sort_msg(bool (*func)(msg,msg)){
    //利用sort函数的三个参数的形式，进行排序
    sort(s.begin(),s.end(),func);
}

//向文件里写入所有记录
void msg_collection::write_all_msg(fstream &ofile){
    //C++11
    for(msg x:s){
        //把光标定位在第id个msg位置，利用id进行存储
        ofile.seekp((x.get_id()-1)*sizeof(msg));
        //强制类型转换，转为const char*类型进行write
        ofile.write(reinterpret_cast<const char*>(&x),sizeof(msg));
    }
}

//打印所有记录
void msg_collection::print_msgs()const{
    //标题
    cout<<setw(8)<<"ID"<<setw(15)<<"Date"<<setw(15)<<"State"<<setw(15)<<"Amount"<<setw(15)<<"Text"<<endl;
    //C++11
    for(msg x:s){
        //已重载<<
        cout<<x;
    }
}

//打印其中一条
void msg_collection::print_msg(int x)const{
    cout<<s[x];
}

//添加一条记录
void msg_collection::add_msg(msg x){
    //往后新开一个空间
    siz++;
    //给它编号
    x.set_id(siz);
    //添加进动态数组
    s.push_back(x);
    Logger::log("添加记录："+to_string(x.get_id())+" "+x.get_date().tostring()+" "+(x.get_ie()?"支出":"收入")+" "+to_string(x.get_amount())+" "+x.get_text());
}

//删除一条记录
int msg_collection::del_msg(int x){
    msg op=s[x-1];
    //先排序，按编号顺序，因为我们要用下标
    sort_msg(&id_oriented);

    //如果金额是0，这条记录不是有效的，已经被删了
    if(s[x-1].get_amount()==0){
        Logger::log("试图删除不存在的记录："+to_string(x));
        return 0;
    }

    //设成0即可，在显示的时候判断一下即可
    s[x-1].set_amount(0);

    //成功删掉
    Logger::log("删除记录："+to_string(op.get_id())+" "+op.get_date().tostring()+" "+(op.get_ie()?"支出":"收入")+" "+to_string(op.get_amount())+" "+op.get_text());
    return 1;
}

//修改一条记录
int msg_collection::mod_msg(int x,msg y){
    //先排序，按编号顺序，因为我们要用下标
    sort_msg(&id_oriented);

    //设为该编号
    y.set_id(x);

    //如果金额是0，这条记录不是有效的，已经被删了
    if(s[x-1].get_amount()==0){
        Logger::log("试图修改不存在的记录："+to_string(x));
        return 0;
    }

    s[x-1]=y;
    msg op=s[x-1];

    //成功修改
    Logger::log("修改记录为："+to_string(op.get_id())+" "+op.get_date().tostring()+" "+(op.get_ie()?"支出":"收入")+" "+to_string(op.get_amount())+" "+op.get_text());
    return 1;
}

void msg_collection::test_1(int a,int b){
    msg x=s[a];
    s[a]=s[b];
    s[b]=x;
}

//重载[]符号，使之可以用对象名直接访问记录
msg &msg_collection::operator[](int x){
    //边界问题
    if(x<0||x>=siz)
        throw out_of_range("Subcript out of range");

    return s[x];
}

msg msg_collection::operator[](int x)const{
    //边界问题
    if(x<0||x>=siz)
        throw out_of_range("Subcript out of range");

    return s[x];
}

//计算三个数值
void msg_collection::calc_msgs(date a,date b){
    //先按日期排序，因为按日期连续区间
    sort_msg(&date_oriented_up);
    
    //总支出 总收入
    double ts1=0,ts2=0;

    //利用二分法找到第一个大于等于起始日期的记录
    int l=0,r=siz;
    while(l<r){
        int mid=(l+r)>>1;
        if(s[mid].get_date()<a) l=mid+1;
        else r=mid;
    }

    //从该记录开始往后找，直到找到比终止日期小的最后一个记录
    for(int i=l;i<siz;i++){
        //比终止日期大了，退出
        if(s[i].get_date()>b) break;
        if(s[i].get_ie()) ts1+=s[i].get_amount();
        else ts2+=s[i].get_amount();
    }

    //净结余=总收入-总支出
    cout<<"The total expenditure from "<<a<<" to "<<b<<" is: "<<ts1<<endl;
    cout<<"The total income from "<<a<<" to "<<b<<" is: "<<ts2<<endl;
    cout<<"The net balance from "<<a<<" to "<<b<<" is: "<<ts2-ts1<<endl;
    Logger::log("查询"+a.tostring()+"到"+b.tostring()+"的金额完成");
}

//打印明细按顺序输出
void msg_collection::print_msgs(date a,date b,int op){
    //先按日期排序，因为按日期连续区间
    sort_msg(&date_oriented_up);
    
    //存满足条件的记录
    vector<msg> res;
    
    //利用二分法找到第一个大于等于起始日期的记录
    int l=0,r=siz;
    while(l<r){
        int mid=(l+r)>>1;
        if(s[mid].get_date()<a) l=mid+1;
        else r=mid;
    }
    
    //从该记录开始往后找，直到找到比终止日期小的最后一个记录
    for(int i=l;i<siz;i++){
        //比终止日期大了，退出
        if(s[i].get_date()>b) break;
        //该记录被删了，不计入
        if(s[i].get_amount()==0) continue;
        res.push_back(s[i]);
    }

    //按何种顺序排序
    if(op==1) sort(res.begin(),res.end(),id_oriented);
    else if(op==2) sort(res.begin(),res.end(),date_oriented_up);
    else if(op==3) sort(res.begin(),res.end(),date_oriented_down);
    else if(op==4) sort(res.begin(),res.end(),amount_oriented_down);
    else if(op==5) sort(res.begin(),res.end(),amount_oriented_up);

    //标题
    cout<<right<<setw(8)<<"ID"<<setw(15)<<"Date"<<setw(15)<<"State"<<setw(15)<<"Amount"<<setw(15)<<"Text"<<endl;
    //C++11
    for(auto x:res) cout<<x;
    cout<<"A total of "<<res.size()<<" accounting records."<<endl;
    Logger::log("查询"+a.tostring()+"到"+b.tostring()+"的明细完成");

    //新增：导出为csv文件
    cout<<endl<<"Whether to export to csv file?(Y/N) ";
    char c;
    cin>>c;
    if(c=='N'){
        cout<<"OK!"<<endl;
    }else{
        cout<<"Name the csv file: ";
        cin.ignore();
        string file_name;
        getline(cin,file_name);
        file_name=file_name+".csv";
        ofstream output(file_name);
        output<<"ID,Date,State,Amount,Text"<<endl;
        for(auto x:res){
            output<<x.get_id()<<','<<x.get_date()<<','<<(x.get_ie()?"Expenditure":"Income")<<','<<x.get_amount()<<','<<x.get_text()<<endl;
        }
        output.close();
        Logger::log("导出成功：文件 "+file_name);
        cout<<"Export successfully!"<<endl;
    }
}

//新增：日志
void Logger::log(const std::string& message) {
    ofstream file("log.txt", ios::app);
    if (!file.is_open()) {
        cerr<<"Logger file could not be opened.\n";
        return;
    }
    
    // 获取当前时间
    time_t now=time(nullptr);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    
    // 写入日志
    file<<"["<<buf<<"] "<<message<<endl;
    file.close();
}