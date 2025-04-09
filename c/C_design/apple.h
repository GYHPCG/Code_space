
#ifndef _APPLE_H
#define _APPLE_H

#ifdef __cplusplus
extern "C"
{
#endif



struct apple_s;//�˴��Ƿ������ýṹ,���п���.

/**
 * @brief  ����ƻ������
 *
 * @param[in] type      ָ��ƻ��������
 * @param[in] weight    ָ��ƻ��������
 * @param[in] price     ָ��ƻ���ļ۸�
 * @param[in] name      ָ��ƻ����
 * @param[in] len       ƻ��������
 *
 * @return  success,����ƻ������ָ��;failed,����NULL
 */
struct apple_s* new_apple(int type, int weight, float price, char* name, int len);

/**
 * @brief  �ͷ�ƻ������
 *
 * @param[in] p ƻ������ָ��
 */
void free_apple(struct apple_s* p);

/* ���ڲ�֪��struct apple_s�ṹ��ĳ�Ա,������Ҫ�ṩAPI�����ʻ��޸ĳ�Ա.
*    ����Ҳ�������˽��ṹ���Աprivate��
*/

/**
 * @brief  ����ƻ������
 *
 * @param[in] p     ƻ������ָ��
 * @param[in] type  ƻ������
 *
 * @return
 */
int set_apple_type(struct apple_s* p, int type);

/**
 * @brief ��ȡƻ������
 *
 * @param p
 *
 * @return
 */
int get_apple_type(struct apple_s* p);

/**
 * @brief ����ƻ������
 *
 * @param p
 * @param weight
 *
 * @return
 */
int set_apple_weight(struct apple_s* p, int weight);

/**
 * @brief  ��ȡƻ������
 *
 * @param p
 *
 * @return
 */
int get_apple_weight(struct apple_s* p);

#ifdef __cplusplus
}
#endif
#endif //_APPLE_H



