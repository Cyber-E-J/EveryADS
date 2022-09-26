from hashlib import new
import nltk
from nltk.book import *
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer

# example_sent = """This is a sample sentence,
#   showing off the stop words filtration."""

ps = PorterStemmer()
stop_words = set(stopwords.words('english'))

new_stop_words = [',','.','?','\'s','!',';','\'t',':','\'d','--','n\'t',
'[','\'ll','\'',']']
for i in new_stop_words:
    stop_words.add(i)

# print(stopwords.words('english'))
# word_tokens = word_tokenize(example_sent)

# filtered_sentence = [w for w in text1 if not w.lower() in stop_words]

# filtered_sentence = []

# for w in text1:
#     if w not in stop_words:
#         filtered_sentence.append(w)


# print(filtered_sentence)


books = ["allswell","asyoulikeit","comedy_errors","cymbeline","lll","measure","merry_wives","merchant","midsummer"
,"much_ado","pericles","taming_shrew","tempest","troilus_cressida","twelfth_night","two_gentlemen"
,"winters_tale",

"1henryiv","2henryiv","henryv","1henryvi","2henryvi","3henryvi","henryviii",
"john","richardii","richardiii",

"cleopatra","coriolanus","hamlet","julius_caesar","lear","macbeth","othello","romeo_juliet",
"timon","titus"
]

# books = ["hamlet_divided"]


for book in books:
    # # 打开文件
    f = open("{}".format(book),"r")
    text = ""
    line = f.readline()
    while line:
        text += line
        line = f.readline()
    f.close()
    text1 = nltk.word_tokenize(text)
    # 或者
    #text1 = nltk.word_tokenize("And now for something completely different. I love you. This is my friend. You are my friend.")

    filtered_sentence = [w for w in text1 if not w.lower() in stop_words]
    # print(filtered_sentence)
    

    f = open("_divided_{}.txt".format(book),"w")
    for word in filtered_sentence:
        # print(ps.stem(word))
        f.write(ps.stem(word)+"\n")
    # FreqDist()获取在文本中每个出现的标识符的频率分布
    fdist = FreqDist(text1)
    print(fdist)
    # 词数量
    print(fdist.N())
    # 不重复词的
    print(fdist.B())