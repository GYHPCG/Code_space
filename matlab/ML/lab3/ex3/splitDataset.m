function subDataset = splitDataset(dataset,axis,value)
%�������ݼ���axisΪĳ�����У� ȡ��������ֵΪvalue����������,��ȥ��������

subDataset = {};
data_size = size(dataset);

%ȡ �������� ������ ��Ӧ�����ݼ�
for i=1:data_size(1)
    data = dataset(i,:);
    if string(data(axis)) == string(value)
        subDataset = [subDataset;[data(1:axis-1) data(axis+1:length(data))]];  %ȡ �������� ������ ��Ӧ�����ݼ�
    end
end
end