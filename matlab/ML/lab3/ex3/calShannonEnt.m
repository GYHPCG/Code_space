function shannonEnt = calShannonEnt(y)
% 计算信息熵


%%%%%================= 下面语句请同学们完成，计算所输入样本集的信息熵 ==================

N=length(y);            %标签长度
    P_T=sum(y)/N;           %正例概率
    P_F=(N-sum(y))/N;         %反例概率
    if(P_T==0||P_F==0)
        %使得p*log2p为0
        shannonEnt = 0; 
        return
    end
    shannonEnt=-(P_T*log2(P_T)+P_F*log2(P_F));  %信息熵

%%%%%%===============================================================================

end

