function shannonEnt = calShannonEnt(y)
% 计算信息熵


%%%%%================= 下面语句请同学们完成，计算所输入样本集的信息熵 ==================

N=length(y);            
    ProT=sum(y)/N;           
    ProF=(N-sum(y))/N;         
    if(ProT~=0 && ProF~=0)
        shannonEnt=-(ProT*log2(ProT)+ProF*log2(ProF));
    else
        shannonEnt = 0;
        return
    end

%%%%%%===============================================================================

end

