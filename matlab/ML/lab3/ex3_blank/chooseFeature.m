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

% ��ʼ����Ϣ��������
gain = zeros(1, M);

% ѭ������ÿ������
for i = 1:M
    % ͳ�Ƶ� i �����ԵĲ�ͬȡֵ������ִ���
    temp = tabulate(x(:, i));
    value = temp(:, 1);            % ����ֵ
    count = cell2mat(temp(:, 2));  % ��ͬ����ֵ�ĸ�������
    Kind_Num = length(value);      % ȡֵ��Ŀ
    
    % ��ʼ��ÿ������ֵ�µ���Ϣ������
    Ent = zeros(Kind_Num, 1);
    
    % ����ÿ������ֵ����Ϣ��
    for j = 1:Kind_Num
        % �ڵ� j ��ȡֵ����������Ŀ
        Ent(j) = calShannonEnt(y(strcmp(x(:, i), value(j))));
    end
    
    % ����� i �����Ե���Ϣ����
    gain(i) = Ent_D - sum(count) / N * sum(Ent);
end

% �����ѡһ�����ֵ
max_gain = find(gain == max(gain));
bestFeature = max_gain(randi(length(max_gain)));





%%%%===================================================================================
end
