data_list = []

def add_data():
    while True:
        input_data = input("Enter data in this format => post_no, number of Likes, number of comments, number of shares\nOr type 'Exit' to finish: ")
        if input_data.lower() == 'exit':
            break
        post_no, likes, comments, shares = map(int, input_data.split(','))
        total_interactions = likes + comments + shares
        data_list.append([post_no, likes, comments, shares, total_interactions])

add_data()

if data_list:
    total_interactions = sum(item[4] for item in data_list)
    average_interactions = total_interactions / len(data_list)
    print(f"Total Interactions: {total_interactions}")
    print(f"Average Interactions per Post: {average_interactions}")
else:
    print("No data entered.")
