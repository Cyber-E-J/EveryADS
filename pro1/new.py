import nltk

#先分句再分词
sents = nltk.sent_tokenize("And now for something completely different. I love you.")
word = []
for sent in sents:
    word.append(nltk.word_tokenize(sent))
print(word)

#分词
text = nltk.word_tokenize("And now for something completely different.")
print(text)

#词性标注
# tagged = nltk.pos_tag(text)
# print (tagged[0:6])

#命名实体识别
# entities = nltk.chunk.ne_chunk(tagged)
# print (entities)
