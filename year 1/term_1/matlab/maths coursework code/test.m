x = [1654 1374 910 1189 1453 1278 818 1047 589 769];
y = [1350 1621 1263 1293 1666 1593 932 1121 1398 1615];

a = sum((x - mean(x)).*(y-mean(y)))/sum((x-mean(x)).^2);

b = mean(y) - mean(x)*a;

r = (numel(x)*sum(x.*y)-sum(x)*sum(y))/sqrt((numel(x)*sum(x.^2)-sum(x)^2)*(numel(y)*sum(y.^2)-sum(y)^2));

d = r^2;

fprintf('a=%f\nb=%f\nr=%f\nd=%f\n',a,b,r,d);
