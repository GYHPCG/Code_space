'''
Author: '破竹' '2986779260@qq.com'
Date: 2024-10-29 21:20:31
LastEditors: '破竹' '2986779260@qq.com'
LastEditTime: 2024-10-29 21:20:46
FilePath: \flask\test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/get_user_info', methods=['GET'])
def get_user_info():
    user_id = request.args.get('user_id')
    # TODO: 查询数据库获取用户信息
    user_info = {'user_id': user_id, 'name': 'hello', 'age': 25}
    return jsonify(user_info)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)

