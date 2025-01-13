clc;
close all;
clear;

%{

input_data = [0 0;0 1;1 0;1 1]';
target_data = [0;1;1;0]';

net=feedforwardnet(10);
net.trainParam.epochs=1000; % 最大训练轮次
net.trainParam.goal=1e-5; % 训练目标误差
net.trainParam.lr=0.1; % 学习率

net.divideParam.trainRatio = 1;
net.divideParam.valRatio = 0;
net.divideParam.testRatio = 0;

[trained_net, tr] = train(net, input_data, target_data);

disp("OK!");

test_data=input_data;
test_output=trained_net(test_data);

disp(round(test_output))

%}

a=[0,1,2,3,4,5,6;7,8,9,10,11,12,13];
[b,c]=mapminmax(a,0,1);
mapminmax('apply',a,c)

%{
view(trained_net);

figure;
plotperform(tr);
title('训练过程中的性能');

figure;
plot(tr.gradient);
xlabel('迭代次数');
ylabel('梯度');
title('训练过程中的梯度');
%}

