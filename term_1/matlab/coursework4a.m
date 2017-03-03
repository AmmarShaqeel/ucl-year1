clear
clc

x = [2329 1593 1479 1857 1335 1140 2136 1844 144 472 1230 2146 1641 1350 2120 1480 1495 3112 2615 2206];
y = [1350 1621 1263 1293 1666 1593 932 1121 1398 1615 2113 1457 1519 1936 1427 1735 1803 1280 1191 1283];

syms z

a = sum((x - mean(x)).*(y-mean(y)))/sum((x-mean(x)).^2);

b = mean(y) - mean(x)*a;

r = (numel(x)*sum(x.*y)-sum(x)*sum( y))/sqrt((numel(x)*sum(x.^2)-sum(x)^2)*(numel(y)*sum(y.^2)-sum(y)^2));

d = r^2;


fprintf('a=%f\nb=%f\nr=%f\nd=%f\n',a,b,r,d);

plot(x,y,'xk');

hold on;

bestfit = fplot(a*z + b,[0,3500],'r');

title('Annual Rainfall against Mean Elevation - Best fit');
ylabel('Annual Rainfall(mm)');
xlabel('Mean Elevation(m)');

hold off
