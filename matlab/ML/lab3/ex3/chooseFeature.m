function bestFeature=chooseFeature(dataset,~)
% ѡ����Ϣ����������������


%baseEntropy = calShannonEnt(dataset);   %���㵱ǰ�ڵ����Ϣ��
%data_size = size(dataset);
%numFeatures = data_size(2) - 1;      %�õ���������
%minEntropy = 2.0;
%bestFeature = 0;
%gain = (1:numFeatures);           %����һ�����飬�Ժ���������ÿ����������Ϣ����    %%%%%%%%%

[N,M]=size(dataset);                %��������N
M=M-1;                              %��������M
y=strcmp(dataset(:,M+1),dataset(1,M+1)); %��ǩy(�Ե�һ����ǩΪ1)
x=dataset(:,1:M);                   %����x
gain = (1:M);                       %����һ�����飬���ڴ���ÿ����������Ϣ����
%bestFeature;                       %�����Ϣ���������
Ent_D=calShannonEnt(y);             %��ǰ��Ϣ��

%%%%====== ���������ͬѧ����ɣ�ѭ��ÿһ������������Ϣ���棬ѡȡ��Ϣ������������ =======

%������Ϣ����
for i=1:M
    % �����i�����Ե�����
    temp=tabulate(x(:,i));
    value=temp(:,1);            %����ֵ
    count=cell2mat(temp(:,2));  %��ͬ����ֵ�ĸ�������
    Kind_Num=length(value);     %ȡֵ��Ŀ
    Ent=zeros(Kind_Num,1);
    % i������ jȡֵ����Ϣ��
    for j=1:Kind_Num
        % �ڵ�j��ȡֵ����������Ŀ
        Ent(j)= calShannonEnt( y(strcmp(x(:,i),value(j))) );
    end
    gain(i)=Ent_D-count'/N*Ent;
end
%�����ѡһ�����ֵ
max_gain=find(gain==max(gain));
choose=randi(length(max_gain));
bestFeature=max_gain(choose);


%%%%===================================================================================
end
