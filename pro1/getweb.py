

from requests_html import HTMLSession
import csv

books = ["allswell","asyoulikeit","comedy_errors","cymbeline","lll","measure","merry_wives","merchant","midsummer"
,"much_ado","pericles","taming_shrew","tempest","troilus_cressida","twelfth_night","two_gentlemen"
,"winters_tale",

"1henryiv","2henryiv","henryv","1henryvi","2henryvi","3henryvi","henryviii",
"john","richardii","richardiii",

"cleopatra","coriolanus","hamlet","julius_caesar","lear","macbeth","othello","romeo_juliet",
"timon","titus"
]

session = HTMLSession()

for book in books:
    file = open('{}'.format(book), 'w', newline='')
    #输入储存对应文件名

    # csvwriter = csv.writer(file)
    # # 写入标题行
    # csvwriter.writerow(['片名'])
    # # 写入数据

    #for i in range(0,1126,15): #1126
    r = session.get('http://shakespeare.mit.edu/{}/full.html'.format(book))
    s_texts = r.html.find('blockquote')
    for s_text in s_texts:
        #print(s_text.text)
        file.write(s_text.text)
        file.write(' ')
        #csvwriter.writerow([title.text])

    # r.html.render()
    # titles = r.html.find('em')
    # dates = r.html.find('span.date')
    # comments = r.html.find('span.comments') 
    # for title in titles:
    #     print(title.text)

    # for html in r.html:
    #     print(html)

file.close()
