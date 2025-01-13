#ifndef MSG_H
#define MSG_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

//date class:used to package date information
class date{

//three protected members:year month day
protected:
    int yr,mth,dy;
public:
    //constructor
    date(int yr=2000,int mth=1,int dy=1):yr(yr),mth(mth),dy(dy){}
    string tostring()const;
    //leap year
    bool is_run()const;
    //date is legal or not
    bool is_right()const;
    //设置月份
    void set_month(int);
    //设置年份
    void set_year(int);
    //设置天
    void set_day(int);
    //设置日期
    void set_date(int,int,int);
    //取私有成员mth
    int get_month()const{return mth;}
    //取私有成员yr
    int get_year()const{return yr;}
    //取私有成员dy
    int get_day()const{return dy;}
    //打印日期
    void print_date(ostream &)const;
    //读取日期
    date read_date(istream &);
    //used to compare date before or after
    bool operator<(const date&);
    bool operator>(const date&);
    //output the date and input the date
    friend ostream &operator<<(ostream &output,const date &x);
    friend istream &operator>>(istream &input,date &x);

};

//msg class:used to package a accounting record
class msg{

//five protected members
protected:
    //每条记录的编号，一个编号只会有一个记录，可以被修改，不会被覆盖
    int id;
    //收入/支出日期
    date t;
    //支出为1，收入为0
    bool is_payout;
    //金额，浮点型
    double amount;
    //备注
    string text;

public:
    //构造函数
    msg(int =0,date =date(),bool =0,double =0,string =" ");
    //取私有成员编号
    int get_id()const;
    //设置编号
    void set_id(int);
    //取私有成员金额
    double get_amount()const;
    //设置金额
    void set_amount(double);
    //设置备注
    void set_text(string);
    //取私有成员备注
    string get_text()const;
    //取私有成员日期
    date get_date()const;
    //取私有成员收入支出状态
    bool get_ie()const;
    //展示记录
    void show_msg()const;
    //输出记录
    void print_msg(ostream &)const;
    //重载流输出运算符，输出记录
    friend ostream &operator<<(ostream &output,const msg &x);
    //friend istream &operator>>(istream &input,msg &x);
    //友元函数，用于排序
    //按编号顺序
    friend bool id_oriented(msg,msg);
    //按日期顺序
    friend bool date_oriented_up(msg,msg);
    //按日期倒序
    friend bool date_oriented_down(msg,msg);
    //按金额降序
    friend bool amount_oriented_up(msg,msg);
    //按金额升序
    friend bool amount_oriented_down(msg,msg);
};

bool id_oriented(msg,msg);
bool date_oriented_up(msg,msg);
bool date_oriented_down(msg,msg);
bool amount_oriented_up(msg,msg);
bool amount_oriented_down(msg,msg);

//记录集类，用于统一管理记录
class msg_collection{



//两个私有成员
//动态数组存储若干条记录
//siz为动态数组的大小，并非记录条数
protected:
    vector<msg> s;
    int siz;

public:
    //explicit构造函数
    explicit msg_collection(int =0);
    //按一定顺序对记录排序
    void sort_msg(bool (*func)(msg,msg));
    //取有效记录个数
    int get_size()const;
    //取私有成员siz
    int get_full_size()const;
    //打印两个日期之间的记录
    void print_msgs(date,date,int);
    //计算两个日期之间的钱
    void calc_msgs(date,date);
    //打印所有记录
    void print_msgs()const;
    //打印一条记录
    void print_msg(int)const;
    //调试用
    void test_1(int,int);
    //添加一条记录
    void add_msg(msg);
    //删除一条记录
    int del_msg(int);
    //调试用
    int test_2(int,int);
    //修改一条记录
    int mod_msg(int,msg);
    //从文件中读取所有记录
    void read_all_msg(fstream &);
    //向文件中写入所有记录
    void write_all_msg(fstream &);
    //重载[]使之可以直接通过对象名访问记录
    msg &operator[](int);
    msg operator[](int)const;

};

//起始按时间顺序显示10条记录
int init_print_msgs();
//输入操作编号
int enter_choice();
//添加
void choice_1();
//删除
void choice_2();
//修改
void choice_3();
//查三个数值
void choice_4();
//查明细
void choice_5();

#endif