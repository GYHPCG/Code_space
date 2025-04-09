function y_test=predict(x_test,mytree,feature_list)
%����

y_test = {};
row = size(x_test);


for j= 1:row(1)
    queue = {mytree};      %�γɶ��У�һ��һ����ȥ
    feature_name = 0;
    feature = 0;
    
    while ~isempty(queue)
        node = queue{1};
        queue(1) = [];                  %�ڶ����г�ȥ�ýڵ�

        tag = 2;
        if string(class(node))~="containers.Map" %Ҷ�ڵ�Ļ������ߵ����ˣ�
            y_test{j} = node;    %�ߵ��׾���������Ҫ�ı�ǩ
            continue
        elseif length(node.keys)==1 %�ڵ�Ļ�
            feature_name = char(node.keys);       %�õ�mytree�ڵ������
            id = ismember(feature_list,feature_name);     %mytree���������ڵ�����
            x = x_test(j,:);
            feature = x(id);                 %�õ��������ݵ���������
            tag = 1;   
        end


        %tag==2 ��Ҫ�����¸��ڵ�
        if tag==2
            if string(class(node))=="containers.Map" 
                keys = node.keys();
                for i = 1:length(keys)
                    key = keys{i};
                    c = char(feature);
                    if strcmp(key,c)
                        queue=[queue,{node(key)}];                  %���б�ɸýڵ�����Ľڵ�
                    end
                end
            end
        end

        %tag==1 ��Ҫѡ����ϲ������ݵ��������ԣ������Ͳ�����������mytree
        if tag==1
            if string(class(node))=="containers.Map" 
                keys = node.keys();
                for i = 1:length(keys)
                    key = keys{i};
                    queue=[queue,{node(key)}];                  %���б�ɸýڵ�����Ľڵ�
                end
            end
        end


    end
end
y_test=predict(x_test,mytree,labels);
fprintf('���������ķ����ǩΪ��');
disp(y_test);

end
    

