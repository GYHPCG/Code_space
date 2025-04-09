
#ifndef _APPLE_H
#define _APPLE_H

#ifdef __cplusplus
extern "C"
{
#endif



struct apple_s;//此处是否声明该结构,可有可无.

/**
 * @brief  创建苹果对象
 *
 * @param[in] type      指定苹果的类型
 * @param[in] weight    指定苹果的重量
 * @param[in] price     指定苹果的价格
 * @param[in] name      指定苹果名
 * @param[in] len       苹果名长度
 *
 * @return  success,返回苹果对象指针;failed,返回NULL
 */
struct apple_s* new_apple(int type, int weight, float price, char* name, int len);

/**
 * @brief  释放苹果对象
 *
 * @param[in] p 苹果对象指针
 */
void free_apple(struct apple_s* p);

/* 由于不知道struct apple_s结构体的成员,所以需要提供API来访问或修改成员.
*    这样也就做到了将结构体成员private化
*/

/**
 * @brief  设置苹果类型
 *
 * @param[in] p     苹果对象指针
 * @param[in] type  苹果类型
 *
 * @return
 */
int set_apple_type(struct apple_s* p, int type);

/**
 * @brief 获取苹果类型
 *
 * @param p
 *
 * @return
 */
int get_apple_type(struct apple_s* p);

/**
 * @brief 设置苹果重量
 *
 * @param p
 * @param weight
 *
 * @return
 */
int set_apple_weight(struct apple_s* p, int weight);

/**
 * @brief  获取苹果重量
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



