function y_test=predict(x_test,mytree,feature_list)
%测试

y_test = {};
row = size(x_test);


for j= 1:row(1)
    queue = {mytree};      %形成队列，一个一个进去
    feature_name = 0;
    feature = 0;
    
    while ~isempty(queue)
        node = queue{1};
        queue(1) = [];                  %在队列中除去该节点

        tag = 2;
        if string(class(node))~="containers.Map" %叶节点的话（即走到底了）
            y_test{j} = node;    %走到底就是我们需要的标签
            continue
        elseif length(node.keys)==1 %节点的话
            feature_name = char(node.keys);       %得到mytree节点的名字
            id = ismember(feature_list,feature_name);     %mytree该特征所在的坐标
            x = x_test(j,:);
            feature = x(id);                 %得到测试数据的特征属性
            tag = 1;   
        end


        %tag==2 即要走入下个节点
        if tag==2
            if string(class(node))=="containers.Map" 
                keys = node.keys();
                for i = 1:length(keys)
                    key = keys{i};
                    c = char(feature);
                    if strcmp(key,c)
                        queue=[queue,{node(key)}];                  %队列变成该节点下面的节点
                    end
                end
            end
        end

        %tag==1 即要选则符合测试数据的特征属性，这样就不用历遍整个mytree
        if tag==1
            if string(class(node))=="containers.Map" 
                keys = node.keys();
                for i = 1:length(keys)
                    key = keys{i};
                    queue=[queue,{node(key)}];                  %队列变成该节点下面的节点
                end
            end
        end


    end
end
y_test=predict(x_test,mytree,labels);
fprintf('测试样本的分类标签为：');
disp(y_test);

end
    

