# python期末答辩

# 项目介绍
本项目旨在通过爬取猫眼电影网站的数据，获取2023暑假热门电影TOP100，并将这些数据进行可视化展示。通过这个项目，我旨在提供给用户一个直观的界面，以便他们了解暑假期间最受欢迎的电影和其他一些电影因素的。

---

# 架构和技术选型

- 本项目使用Flask框架作为后端开发工具，这个框架简洁高效，适合构建轻量级的Web应用程序。
- 在虚拟环境venv中进行开发，以保持项目的独立性和可维护性。
- 网页模板存放在模板文件夹templates中，静态资源如图片等存放在静态文件夹static中。
- 为了美化界面，我选择了Bootstrap前端框架，以确保用户获得良好的使用体验。
- 数据分析和可视化方面，我采用了ECharts库，这是一款功能强大且易于使用的图表库。

---
# 功能和实现

通过编写爬虫程序，我成功爬取了猫眼电影网站的2023暑假电影TOP100的相关信息，包括电影名称、评分、主演等。使用Flask框架，我搭建了一个简单的Web应用程序，通过路由和视图函数将数据传递给前端页面。在前端页面中，我使用Bootstrap框架美化界面，并使用ECharts库创建了直观而具有吸引力的数据可视化图表。用户可以通过网页应用程序浏览电影列表、查看电影详情和观看电影评分趋势等可视化图表。

1. 爬虫代码：

   ```python
   import time, random, hashlib, requests, jsonpath, re, ddddocr, io
   import csv
   from fontTools.ttLib import TTFont
   from PIL import ImageFont, Image, ImageDraw
   import ssl
   
   
   # 爬取网页
   # 解析数据
   # 保存数据
   def main():
       orderType = 0  # 0:综合票房，1分账票房
       url = ""
       uuid = '18912024041c8-00c0649fd522a4-3b626b4b-13c680-18912024043c8'  # uuid是写“死”的，直接去网页中寻找即可
       timeStamp = int(time.time() * 1000)  # 获取时间戳
       key = 'A013F70DB97834C0A5492378BD76C53A'  # signKey中d的值
       ua = 'TW96aWxsYS81LjAgKE1hY2ludG9zaDsgSW50ZWwgTWFjIE9TIFggMTBfMTVfNykgQXBwbGVXZWJLaXQvNjA1LjEuMTUgKEtIVE1MLCBsaWtlIEdlY2tvKSBWZXJzaW9uLzE2LjUgU2FmYXJpLzYwNS4xLjE1'  # ua也是写“死”的，直接去网页即可寻找到
       index = int(1000 * random.random() + 1)  # 获得动态变化的index
       enstr = f'method=GET&timeStamp={timeStamp}&User-Agent={ua}&index={index}&channelId=40009&sVersion=2&key={key}'  # d[o(262)]的计算结果
       signKey = hashlib.md5(enstr.encode(encoding='UTF-8')).hexdigest()  # 查询signKey的计算方法，发现他的signkey是根据hashmd5计算得到的
       url = f'https://piaofang.maoyan.com/dashboard-ajax/movie?orderType={orderType}&uuid={uuid}&timeStamp={timeStamp}&User-Agent={ua}&index={index}&channelId=40009&sVersion=2&signKey={signKey}'  # 利用上面获取到动态变化的信息组合起来得到具体的url，格式参考网页中url的格式
       askURL1(url)  # 带着得到的url，去爬取网页
   
   
   def saveData(datalist, size):
       csvfile = open('maoyan2.csv', mode='w', newline='', encoding='utf-8')
       fileidnames = ["影片", "上映天数", "总票房", "综合票房", "票房占比", "排片场次", "拍片占比", "场均人次", "上座率"]
       write = csv.DictWriter(csvfile, fieldnames=fileidnames)
       write.writeheader()
       for i in range(0, size):
           write.writerow({"影片": datalist[i][0], "上映天数": datalist[i][1], "总票房": datalist[i][2],
                           "综合票房": datalist[i][3], "票房占比": datalist[i][4], "排片场次": datalist[i][5],
                           "拍片占比": datalist[i][6], "场均人次": datalist[i][7], "上座率": datalist[i][8]})
       print("成功！！！！！！！！！！！")
   
   
   def askURL1(url):
       ocr = ddddocr.DdddOcr()  # 创建一个ocr对象，便于下面利用其识别图像中的数字
       ssl._create_default_https_context = ssl._create_unverified_context  # 防止出现certificate verify faile错误
       headers = {  # 模拟浏览器头部信息，向服务器端发送消息
           'Accept': 'application/json, text/plain, */*',
           'Refer': 'https://piaofang.maoyan.com/dashboard/movie',
           'cookies': '_lx_utm=utm_source%3DBaidu%26utm_medium%3Dorganic; _lxsdk_s=1891fe8c651-c04-744-b43%7C%7C7; uuid=18912024041c8-00c0649fd522a4-3b626b4b-13c680-18912024043c8; _lxsdk=18912024041c8-00c0649fd522a4-3b626b4b-13c680-18912024043c8; _lxsdk_cuid=18912024041c8-00c0649fd522a4-3b626b4b-13c680-18912024043c8',
           'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/16.5 Safari/605.1.15'
           # 去网页查找即可
       }  # 让服务器端理解我们是一个浏览器，而不是一个爬虫（如果被发现为爬虫，会报出418的错误）
       # User—Agent：本质上告诉浏览器，我们可以接受什么水平的内容
       html = requests.get(url, headers=headers, verify=False)  # 利用requests去模拟浏览器向网页发送请求消息，得到服务器返回的网页信息
       fonturl = 'http:' + re.search('opentype"\),url\("(//.*?\.woff)"', html.json()['fontStyle']).group(
           1)  # 由于网页中的综合票房是被设计成反爬的字符的，所以我们需要去获取网页中字体的下载地址，以便于对字体进行反爬
       r = requests.get(fonturl)  # 根据获取到的字体的下载地址，利用requests请求获得字体
       with open('../temp.woff', 'wb') as f:  # 以二进制格式打开文件temp只用于写入，如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。
           f.write(r.content)  # 将获取到的字体写入
           f.close  # 关闭文件
       tfont = TTFont("../temp.woff")  # 实例化TTFont
       uni_list = tfont.getGlyphOrder()[2:]  # 通过字型名称选择字型对象，因为根据从官网下载的font字体在font.editor解析后发现前两位是无用的，所以从2开始
       print('uni列表：', uni_list)  # 打印从文件中获取到的字型对象
       charList = []
       # 由于字体的unicode编码是变化的，所以主要的思想就是，根据unicode画出其代表的数字，并且最后使用ocr识别出图像中的数字
       font = ImageFont.truetype("temp.woff", 40)  # TrueType可以描述字体的外形轮廓，并且无论是放大还是缩小，字体都是光滑的，不会有锯齿现象
       # 加载一个TrueType字体文件，并且创建一个字体对象，这个函数从指定的文件加载了一个字体对象，并且为指定大小的字体创建了字体对象，以便于下边对字体反爬
       # 将10个uni字符画到im，进而使用ocr识别获得对应数字
       for uchar in uni_list:  # 将获取到的uni逐一的绘画出来，并且识别
           unknown_char = f"\\u{uchar[3:]}".encode().decode(
               "unicode_escape")  # 由于每一个数字的编码格式都是uni...所以从第三位开始，为了防止乱码，所以进行逐一解码，对字符串进行unicode_escape解码
           # unicode_escape是一种编码集，这种编码的格式可以直接将unicode编码存储进文件
           im = Image.new(mode='RGB', size=(42, 40), color="white")  # 使用Image库绘图，创建一个新的图像，使用RGB模式，颜色为白色
           draw = ImageDraw.Draw(im=im)  # 在原始图像的基础上创建一个ImageDraw.Draw()实例
           draw.text(xy=(0, 0), text=unknown_char, fill=0, font=font)  # 绘图，从文本左上角处开始画，需要绘制的文本内容为上面解码的结果，颜色为黑色
           img_byte = io.BytesIO()  # 创建一个字节流管道，便于下边用ocr根据从字节流管道中获取到的二进制转换为指定的字符数字
           im.save(img_byte, format='JPEG')  ## 将图片数据存入字节流管道， format可以按照具体文件的格式填写
           charList.append(ocr.classification(img_byte.getvalue()))  # 根据从字节流通道中获取到的二进制利用ocr识别，并且转换为指定的字符，添加到charList中
       print('对应字符：', charList)
       # 下面利用json库解析需要获取的数据，因为这些信息是存储在json的文档中相当于是
       moviename = jsonpath.jsonpath(html.json(),
                                     '$.movieList.list..movieInfo.movieName')  # 解析电影名字，$根结点，解析根结点下的list下的无论什么位置的movieInfo.movieName
       movieInfo = jsonpath.jsonpath(html.json(), '$.movieList.list..movieInfo.releaseInfo')  # 解析上映天数
       sumBoxDesc = jsonpath.jsonpath(html.json(), '$.movieList.list..sumBoxDesc')  # 解析上映天数内的总票房
       enNum = jsonpath.jsonpath(html.json(), '$.movieList.list..boxSplitUnit.num')  # 解析综合票房
       enNumDw = jsonpath.jsonpath(html.json(), '$.movieList.list..boxSplitUnit.unit')  # 解析综合票房的单位
       boxRate = jsonpath.jsonpath(html.json(), '$.movieList.list..boxRate')  # 解析票房占比
       showCount = jsonpath.jsonpath(html.json(), '$.movieList.list..showCount')  # 解析排片场次
       countRate = jsonpath.jsonpath(html.json(), '$.movieList.list..showCountRate')  # 解析拍片占比
       showView = jsonpath.jsonpath(html.json(), '$.movieList.list..avgShowView')  # 解析场均人次
       setView = jsonpath.jsonpath(html.json(), '$.movieList.list..avgSeatView')  # 解析上坐率
       # 以上对所需要获取的数据的解析，道理皆相同，重点在于路径的编写，路径的编写需要去网页端的源代码里调出movie的json文档，根据json文档的结构进行编写
       datalist = [[0 for i in range(9)] for i in range(len(moviename))]  # 存储电影的信息
       # 解析票房的信息
       # 解析票房信息
       # enNum获取到的字符串为['&#xe83f;&#xed98;&#xed98;&#xe916;.&#xe83f;&#xedba;', '&#xe916;&#xed98;&#xed98;&#xe916;.&#xf70e;&#xefe9,........]
       for j in range(len(moviename)):
           tmpstr = enNum[j].split(';')  # 将获取到的第j个电影的enNum字符串切割为字符串数组，返回新的字符串数组用tmpstr接收，每一个变量之间用','分隔,分隔时以';'结尾
           rstr = ''
           for i in tmpstr:  # 解析获取到的第j个电影的综合票房信息，也就是解析&#xe83f此类代表的具体数字为多少
               if i == '': continue  # 由于第j个电影的综合票房的特殊字符串数组以''结尾，所以当i==''时表示已经解析完第j个电影的综合票房数据['&#xe83f', '&#xed98', '&#xed98', '&#xe916', '.&#xe83f', '&#xedba', '']
               tmp = 'uni' + i.replace('&#x', '', 1).replace('.',
                                                             '').upper()  # 将&#x字符串替换为''并且最多替换一次，再用''替换新得到的字符串中的'.',因为解析出来后有的字符串前边还会有'.'---'.&#xe83f'，最后转换为大写
               for k in range(len(uni_list)):  # 将上边得到的uni开头的字符串与从官网下载的uni字符对比
                   if tmp == uni_list[k]:  # 当解析出来的uni与官网中的uni字符串相对应，即得到相应的uni表示的具体数字
                       if '.' in i:  # 如果小数点.在特殊字符中，例如'.&#xe83f'，则此位的前边需要加上小数点，因为此时解析的特殊字符已经是小数位了
                           rstr = rstr + '.' + charList[
                               k]  # 由于上边已经将从官网得到的uni字符编码的数字与网页中的'&#xe83f'解析得到的uni字符匹配上，所以只需将uni对应的数字加入到综合数据票房中
                       else:
                           rstr = rstr + charList[k]  # 与上一句同理
                       break
           for num in range(0, 9):  # 将获取到的数据存入到数组中
               if num == 0:
                   datalist[j][num] = moviename[j]
               if num == 1:
                   datalist[j][num] = movieInfo[j]
               if num == 2:
                   datalist[j][num] = sumBoxDesc[j]
               if num == 3:
                   datalist[j][num] = rstr + enNumDw[j]
               if num == 4:
                   datalist[j][num] = boxRate[j]
               if num == 5:
                   datalist[j][num] = showCount[j]
               if num == 6:
                   datalist[j][num] = countRate[j]
               if num == 7:
                   datalist[j][num] = showView[j]
               if num == 8:
                   datalist[j][num] = setView[j]
       saveData(datalist, len(moviename))  # 保存数据
   
   
   if __name__ == "__main__":
       main()
   
   ```

   

1. 数据清洗，首先由于从猫眼爬到的票房中存在*1亿，2.5万， 6%， <1%*这样的数据，在比较数据大小，统计过程和建图中产生不便，所以我们首先用了一个deal_data.py的python代码对其中的1亿，345.6万这样的数据进行了处理，并保存为output.csv文件。然后在==app,py==中，我们用了一个列表**item**来存放我们从output.csv文件中读取的数据。

```py
# 将读进来的input_file文件,修改成output_file文件
def process_csv(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as file:
        reader = csv.reader(file)
        rows = list(reader)

    # 处理数据
    for row in rows:
        for i in range(2, len(row)):
            value = row[i]
            if '万' in value:
                number = float(value.replace('万', '')) * 10000
                row[i] = str(number)
            elif '亿' in value:
                number = float(value.replace('亿', '')) * 100000000
                row[i] = str(number)

    with open(output_file, 'w', encoding='utf-8', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(rows)
        
    powershell的默认路径：%HOMEDRIVE%%HOMEPATH%
```



2. 渲染html的模板，并传递了一些参数进去，模板可以使用这些变量来动态生成HTML内容，然后将生成的内容作为HTTP响应返回给用户。

```py
app = Flask(__name__)  # Flask的构造函数，当前模块的名称(__name__)作为参数

# Flask类的route()函数是一个装饰器，它告诉应用程序哪个URL应该调用相关的函数
@app.route('/')  
# 使用了render_template函数来渲染一个名为index.html的模板，并将一些变量items、sum1、sum10、sumll
# 、county、num、date、date_sum、county_items传递给模板。模板可以使用这些变量来动态生成HTML内容，
# 然后将生成的内容作为HTTP响应返回给用户。
# 总体来说，这个路由函数的作用是处理用户对根URL的请求，然后渲染一个包含动态内容的HTML页面并返回给用户。
def anc():
    return render_template('index.html', items=items, sum1=sum1, sum10=sum10, sumll=sumll, county=sk, num=sv, date=date,
                           date_sum=date_sum,
                           county_items=county_items)
    
    
```

3. echarts画图：echarts画图的方法流程固定

   ```html
    <div id="main" style="width: 700px;height:400px;"></div>
                       <script type="text/javascript">
                         // 基于准备好的dom，初始化echarts实例
                               var myChart = echarts.init(document.getElementById('main'));
                               // 指定图表的配置项和数据
                               var option = {
                                   title: {
                                       text: 'TOP20电影票房'
                                   },
                                   tooltip: {},
                                   legend: {
                                       data: ['票房']
                                   },
                                   xAxis: {
                                       data: [{% for item in items[:20] %}'{{item[0]}}', {% endfor %}],
                                       axisTick: {alignWithLabel: true},
                                       axisLabel: {rotate: 45}
                                   },
                                   yAxis: {
                                         // type: 'category',
                                         // data: [{% for item in items %}'{{item[0]}}',{% endfor %}],
                                   },
                                   series: [{
                                           name: '票房',
                                           type: 'bar',
                                           data: [{% for item in items[:20] %}'{{ item[2] }}',{% endfor %}]
                                   }]
                                   }
                               // 使用刚指定的配置项和数据显示图表。
                               myChart.setOption(option);
   
                           </script>
   ```




# 成果展示
请允许我通过屏幕分享向大家展示我的网页应用程序和数据可视化图表。在网页应用程序中，您将能够浏览猫眼电影TOP100列表，点击电影名称查看详细信息，并通过图表了解电影评分趋势和排名情况。

# 总结和展望

通过这个项目，我不仅学到了如何使用Flask框架进行Web开发，还提升了对数据可视化的理解和实践能力。在未来，我希望能进一步完善这个系统，加入更多的功能和交互性，使其成为用户了解电影热门趋势的首选工具。

非常感谢您的聆听！我很高兴能够分享我的项目经验，并期待收到您的宝贵意见和建议。谢谢！