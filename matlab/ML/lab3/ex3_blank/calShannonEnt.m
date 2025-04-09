function shannonEnt = calShannonEnt(y)
% ������Ϣ��


%%%%%================= ���������ͬѧ����ɣ���������������������Ϣ�� ==================

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

