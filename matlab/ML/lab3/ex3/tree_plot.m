function tree_plot(p,nodevalue,branchvalue)
% �ο�treeplot

[x,y,h] = treelayout(p); %x:�����꣬y:�����ꣻh:�������
f = find(p~=0); %��0�ڵ�
pp = p(f); %��0ֵ
X = [x(f); x(pp); NaN(size(f))];
Y = [y(f); y(pp); NaN(size(f))];

X = X(:);
Y = Y(:);

n = length(p);
if n<500
    hold on;
    plot(x,y,'ro',X,Y,'r-')
    nodesize = length(x);
    for i=1:nodesize
        text(x(i)+0.01,y(i),nodevalue{1,i});      
    end
    for i=2:nodesize
        j = 3*i-5;
        text((X(j)+X(j+1))/2-length(char(branchvalue{1,i-1}))/200,(Y(j)+Y(j+1))/2,branchvalue{1,i-1})
    end
    hold off
else
    plot(X,Y,'r-');
end
xlabel(['height = ' int2str(h)]);
axis([0 1 0 1]);
end

