
import sys
from urlparse import urlparse

def reducer():

	key = None

	for each_line in sys.stdin:
		data = each_line.strip().split('\t')

		if len(data) != 3:
			continue

		Subject, Predicate, Object = data
		domain_subject = return_url(Subject)
		




def return_url(url):
	parsed_uri = urlparse(url)
	domain = '{uri.scheme}://{uri.netloc}/'.format(uri=parsed_uri)
	return domain
