%%  清空环境变量
warning off             % 关闭报警信息
close all               % 关闭开启的图窗
clear                   % 清空变量
clc                     % 清空命令行
load("Newyork.mat");

%%  导入数据
res = readmatrix('Newyork_ver0.3.csv');
% res = rmoutliers(res,'quartiles');
%%  划分训练集和测试集
% res(1,:)=[];

P_test = res(1: end, 1: 118)';
T_test = res(1: end, 119)';
N = size(P_test, 2);

for i=1:118

%%  数据归一化
[p_test, ps_input] = mapminmax(P_test, 0, 1);

[t_test, ps_output] = mapminmax(T_test, 0, 1);

temp=randperm(69987);
p_test_new=p_test;
p_test_new(i,:)=p_test(i,temp(1:69987));

%%  仿真测试
t_sim = sim(net, p_test_new);

%%  数据反归一化
T_sim = mapminmax('reverse', t_sim, ps_output);

%%  均方根误差
error(1,i) = sqrt(sum((T_sim - T_test ).^2) ./ N);

end

bar([mean(error(1,1:5)),mean(error(1,6)),mean(error(1,7:55)),mean(error(1,56)),mean(error(1,57)),mean(error(1,58)),mean(error(1,59)),mean(error(1,60)),mean(error(1,61:64)),mean(error(1,65:118))])
