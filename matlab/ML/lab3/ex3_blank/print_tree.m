
function [nodeids_,nodevalue_,branchvalue_] = print_tree(tree)
% �������������������nodeids���ڵ��ϵ����nodevalue���ڵ���Ϣ����branchvalue��֦����Ϣ��
nodeids(1) = 0;
nodeid = 0;
nodevalue={};
branchvalue={};

queue = {tree} ;      %�γɶ��У�һ��һ����ȥ
while ~isempty(queue)
    node = queue{1};
    queue(1) = [];                  %�ڶ����г�ȥ�ýڵ�
    if string(class(node))~="containers.Map" %Ҷ�ڵ�Ļ������ߵ����ˣ�
        nodeid = nodeid+1;
        nodevalue = [nodevalue,{node}];
    elseif length(node.keys)==1 %�ڵ�Ļ�
        nodevalue = [nodevalue,node.keys];      %����ýڵ���
        node_info = node(char(node.keys));      %����ýڵ��µ����Զ�Ӧ��map
        nodeid = nodeid+1;
        branchvalue = [branchvalue,node_info.keys];   %ÿ���ڵ��µ�����
        for i=1:length(node_info.keys)
            nodeids = [nodeids,nodeid];
        end

        
    end
    
    if string(class(node))=="containers.Map" 
        keys = node.keys();
        for i = 1:length(keys)
            key = keys{i};
            queue=[queue,{node(key)}];                  %���б�ɸýڵ�����Ľڵ�
        end
    end
nodeids_=nodeids;
nodevalue_=nodevalue;
branchvalue_ = branchvalue;
end